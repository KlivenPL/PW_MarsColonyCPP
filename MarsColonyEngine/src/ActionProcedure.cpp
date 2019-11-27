#include "pch.h"
#include "ActionProcedure.h"

bool ActionProcedure::checkRequirements(IActionHandler& handler, std::string& outStr){
	return this->checkRequirementsFunc(handler, outStr);
}

bool ActionProcedure::executeAction(IActionHandler& handler, const std::string args, std::string& outStr) {
	return this->executeActionFunc(handler, args, outStr);
}
