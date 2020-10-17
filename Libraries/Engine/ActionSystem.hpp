// MIT Licensed (see LICENSE.md).
#pragma once

namespace Plasma
{

typedef InList<Actions> ActiveListsType;
class UpdateEvent;

/// Space component that synchronizes action queues.
class ActionSpace : public Component
{
public:
  LightningDeclareType(ActionSpace, TypeCopyMode::ReferenceType);

  ActionSpace();
  ~ActionSpace();

  // Component Interface
  void Initialize(CogInitializer& initializer) override;

  // Time Space handler
  void OnActionFrameUpdate(UpdateEvent* updateEvent);
  void OnActionLogicUpdate(UpdateEvent* updateEvent);
  void UpdateActions(UpdateEvent* updateEvent, ActionExecuteMode::Enum mode);

  ActiveListsType ActiveLists;
  ActiveListsType ScheduledLists;
};

} // namespace Plasma
