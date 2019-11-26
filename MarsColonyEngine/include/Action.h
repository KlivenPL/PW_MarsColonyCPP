#pragma once
#include "pch.h"
#include "ActionType.h"
#include "ActionHandler.h"
#include "ActionProcedure.h"
class Action {
private:
	ActionType actionType = ActionTypeNone;
	std::string actionName;
	ActionProcedure* actionProcedure;
	static std::vector <Action*> actionDb;
protected:
	static void registerAction(Action* action);
public:
	Action(ActionType actionType, std::string actionName) :
		actionType(actionType), actionName(actionName) {};
	~Action();

	void execute(ActionType type, ActionHandler& handler, const std::string& args);
};
