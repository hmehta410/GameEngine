#pragma once

//just a generic iterator class
//covariant virtual methods would have been preferable except for the void* preventing it. 
class Iterator
{
public:
	virtual ~Iterator() = default;
	inline void* First(Iterator* = nullptr) { return privFirst(); }
	inline void* Next(Iterator* = nullptr) { return privNext(); }
	inline bool IsDone(Iterator* = nullptr) const { return privIsDone(); }
	inline void* CurrentItem(Iterator* = nullptr) { return privCurrentItem(); }

protected:
	virtual void* privFirst() = 0;
	virtual void* privNext() = 0;
	virtual bool privIsDone() const = 0;
	virtual void* privCurrentItem() const = 0;
};