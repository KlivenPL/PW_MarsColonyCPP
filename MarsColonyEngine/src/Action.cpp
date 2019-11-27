#include "pch.h"
#include "Action.h"

void Action::registerAction(Action *action) {
	for (auto tmpAction : actionDb) {
		if (tmpAction->actionType == action->actionType) {
			throw std::invalid_argument("Given action type is already registered");
			return;
		}
	}
	actionDb.push_back(action);
}

Action::~Action(){
	std::cout << "Unregistering action " << actionName << std::endl;
	int id = 0;
	auto it = std::find(actionDb.begin(), actionDb.end(), this);
	if (it != actionDb.end())
		actionDb.erase(it);
}

void Action::execute(ActionType type, IActionHandler & handler, const std::string& args) {
	Action *action = nullptr;
	for (auto tmpAction : actionDb) {
		if (tmpAction->actionType == type) {
			action = tmpAction;
			break;
		}
	}
	if (action == nullptr) {
		throw std::invalid_argument("Given action type is not registered");
	}
	std::string outStr;
	if (action->actionProcedure->checkRequirements(handler, outStr)) {
		if (action->actionProcedure->executeAction(handler, args, outStr)) {
			std::cout << "Action " + action->actionName + " executed successfully." << std::endl;
			return;
		}
		throw std::invalid_argument("Action could not be executed: " + outStr);
		return;
	}
	std::cout << "Action " + action->actionName + " has not met the requirements: " << outStr << std::endl;

}