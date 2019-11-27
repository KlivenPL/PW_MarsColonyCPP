#include "pch.h"
#include "ActionProcedure.h"

bool ActionProcedure::checkRequirements(std::string& outStr){
	return this->checkRequirementsFunc(outStr);
}

bool ActionProcedure::executeAction(const std::string args, std::string& outStr) {
	return this->executeActionFunc(args, outStr);
}
