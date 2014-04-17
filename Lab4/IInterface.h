#pragma once
class IInterface
{
public:
	IInterface();
	virtual ~IInterface();
	virtual void comparison_age(IInterface&) = 0;
};

