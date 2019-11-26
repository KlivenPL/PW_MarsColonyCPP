#include "pch.h"
#include "ActionProcedure.h"

bool ActionProcedure::checkRequirements(ActionHandler& actionHandler, std::string& outStr){
	return this->checkRequirementsFunc(actionHandler, outStr);
}

bool ActionProcedure::executeAction(ActionHandler& actionHandler, const std::string args, std::string& outStr) {
	return this->executeActionFunc(actionHandler, args, outStr);
}
