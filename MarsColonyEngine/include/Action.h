#pragma once
#include "pch.h"
#include "ActionType.h"
#include "ActionProcedure.h"
class Action {
private:
	ActionType actionType = ActionTypeNone;
	std::string actionName;
	ActionProcedure* actionProcedure;
	inline static std::vector <Action*> actionDb;
public:
	static void registerAction(Action* action);
	Action(ActionType actionType, std::string actionName, ActionProcedure * actionProcedure) :
		actionType(actionType), actionName(actionName), actionProcedure(actionProcedure) {};
	~Action();

	static void execute(ActionType type, IActionHandler& handler, const std::string& args);
};
