#pragma once
class Action
{
public:
	virtual void ExecuteAction() = 0;
	virtual bool ReturnPrecondition() = 0;
	virtual bool CheckPrecondition() = 0;
protected:
	bool precondition;
};