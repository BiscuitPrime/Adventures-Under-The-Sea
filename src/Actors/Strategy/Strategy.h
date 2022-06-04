#pragma once

class Strategy {
public:
	virtual ~Strategy() = default;
	virtual void execute() const = 0;
};