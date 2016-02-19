template<typename T>
class SmartPoint
{
public:
	SmartPoint():users(new size_t(1)),p(new T()){}         //默认构造函数
	SmartPoint(const SmartPoint &sp):users(sp.users),p(sp.p){++*users;}   //拷贝构造函数
	SmartPoint& operator=(const SmartPoint &sp)            //赋值运算符重载
	{
		++*sp.users;    //先对右边指针引用计数+1，解决自我复制存在的问题
		if (--*users==0)
		{
			delete users;
			delete p;
		}
		users = sp.users;
		p = sp.p;
		return *this;
	}
	~ SmartPoint()
	{
		if (--*users==0)
		{
			delete users;
			delete p;
		}
	}
private:
	size_t *users;
	T *p;
};