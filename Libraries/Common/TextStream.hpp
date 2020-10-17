// MIT Licensed (see LICENSE.md).
#pragma once
#include "StringBuilder.hpp"

namespace Plasma
{

// Simple callback interface for process stdio
class TextStream
{
public:
  virtual void Write(cstr text) = 0;
  virtual ~TextStream(){};
};

class TextStreamDebugPrint : public TextStream
{
  virtual void Write(cstr text)
  {
    PlasmaPrintFilter(Filter::DefaultFilter, "%s", text);
  }
};

class TextStreamBuffer : public TextStream
{
public:
  StringBuilder buffer;
  String ToString()
  {
    return buffer.ToString();
  }
  void Write(cstr text) override
  {
    buffer.Append(text);
  }
};

class TextStreamNull : public TextStream
{
  void Write(cstr text) override{};
};

} // namespace Plasma
