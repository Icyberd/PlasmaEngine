#pragma once

namespace Plasma
{
    struct DeviceSuitabilityData
    {
        VkSurfaceKHR mSurface;
        void* mUserData;
        typedef bool(*DeviceSuitableFn)(VkPhysicalDevice physicalDevice, DeviceSuitabilityData* data);
        DeviceSuitableFn mDeviceSuitabilityFn;

        DeviceSuitabilityData() : mUserData(nullptr), mDeviceSuitabilityFn(nullptr)
        {

        }
    };

    struct PhysicsDeviceSelectionData
    {
        VkInstance mInstance;
        DeviceSuitabilityData mSuitabilityData;
    };

    struct PhysicsDeviceResultData
    {
        VkPhysicalDevice mPhysicalDevice;
    };

    inline void SelectPhysicsDevice(PhysicsDeviceSelectionData& selectionData, PhysicsDeviceResultData& resultData)
    {
        resultData.mPhysicalDevice = VK_NULL_HANDLE;
        uint32_t deviceCount = 0;
        vkEnumeratePhysicalDevices(selectionData.mInstance, &deviceCount, nullptr);

        if(deviceCount == 0)
            ErrorIf(true, "failed to find GPUs with Vulkan support!");

        Array<VkPhysicalDevice> devices(deviceCount);
        vkEnumeratePhysicalDevices(selectionData.mInstance, &deviceCount, devices.Data());

        for(int i = 0 ; i < devices.Size(); i++)
        {
            bool isSuitable = selectionData.mSuitabilityData.mDeviceSuitabilityFn(devices[i], &selectionData.mSuitabilityData);
            if(isSuitable)
            {
                resultData.mPhysicalDevice = devices[i];
                break;
            }
        }

        if(resultData.mPhysicalDevice == VK_NULL_HANDLE)
            ErrorIf(true, "failed to find a suitable GPU!");
    }

    struct PhysicalDeviceLimits
    {
        uint32_t mMaxUniformBufferRange;
        VkDeviceSize mMinUniformBufferOffsetAlignment;
    };

    inline void QueryPhysicalDeviceLimits(VkPhysicalDevice physicalDevice, PhysicalDeviceLimits& results)
    {
        VkPhysicalDeviceProperties properties;
        vkGetPhysicalDeviceProperties(physicalDevice, &properties);

        results.mMaxUniformBufferRange = properties.limits.maxUniformBufferRange;
        results.mMinUniformBufferOffsetAlignment = properties.limits.minUniformBufferOffsetAlignment;
    }
}