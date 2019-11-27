#pragma once
#include "pch.h"
#include "IActionHandler.h"
#include <functional>
class ActionProcedure {
private:
	std::function<bool(std::string & outStr)> checkRequirementsFunc;
	std::function<bool(const std::string & args, std::string &outStr)> executeActionFunc;
public:
	bool checkRequirements(std::string& outStr);
	bool executeAction(std::string args, std::string& outStr);

	ActionProcedure(std::function<bool(std::string & outStr)> requirements,
		std::function<bool(const std::string & args, std::string & outStr)> exec):
		checkRequirementsFunc(requirements), executeActionFunc(exec) {};
};

