#ifndef MY_LOGICAL_FLOAT_CLASS_HEADER_INCLUDED__FD8198C9-B365-40D7-A2EC-7D37712DB6BF____
#define MY_LOGICAL_FLOAT_CLASS_HEADER_INCLUDED__FD8198C9-B365-40D7-A2EC-7D37712DB6BF____

#include <SysUtils.hpp>

//class MyLogFloat;
//MyFloat operator+(double val, MyFloat myFloat);

class MyLogFloat
{
public:
	// конструкторы
	explicit MyLogFloat() : has_got_(0),val_(0) {}
    MyLogFloat(const AnsiString& s) : val_(), has_got_( TryStrToFloat(s, val_) )
    {
		if (!has_got_) val_ = 0;
    }

    MyLogFloat(double val) : val_(val), has_got_(1) {}
    MyLogFloat(const MyLogFloat& obj) : val_(obj.val_), has_got_(obj.has_got_) 
	{
		if (!has_got_) val_ = 0;
	}


    // присваивание
    MyLogFloat operator=(const MyLogFloat& obj)
    {
    	has_got_ = obj.has_got_;		
		val_ = has_got_ ? obj.val_ : 0;
        return *this;
    }

	MyLogFloat operator=(double val)
    {
    	val_ = val;
        has_got_ = 1;
        return *this;
    }

    MyLogFloat operator=(const AnsiString& s)
    {
        has_got_ = TryStrToFloat(s, val_);
		if (!has_got_) val_ = 0;
        return *this;
    }

    // опреции преобразования
    AnsiString ToStr( const AnsiString& fmt = "" ) const
    {
    	if(!has_got_) return "";
        if(fmt == "") return FloatToStr(val_);
        return FormatFloat( fmt, val_ );
    }
    double Get() const   { return val_;  }
    double HasGot() const   { return has_got_;  }

    // арифметические операторы
    #define DECLARE_AND_DEFINE_DOUBLE_OPERATOR___(op) \
    MyLogFloat operator##op##(double val)\
    {\
        MyLogFloat ret(*this);\
    	ret.val_##op##=val;\
        return ret;\
    }\
    friend MyLogFloat operator##op##(double val, const MyLogFloat& obj)\
    {\
     	MyLogFloat ret(obj);\
    	ret.val_##op##=val;\
        return ret;\
    }\
    MyLogFloat operator##op##(const MyLogFloat& obj)\
    {\
    	MyLogFloat ret(*this);\
    	ret.val_##op##=obj.val_; has_got_ = has_got_ && obj.has_got_;\
        return ret;\
    }\
    MyLogFloat operator##op##=(double val)\
    {\
        return (*this) + val;\
    }

    DECLARE_AND_DEFINE_DOUBLE_OPERATOR___(+)
    DECLARE_AND_DEFINE_DOUBLE_OPERATOR___(-)
    DECLARE_AND_DEFINE_DOUBLE_OPERATOR___(*)
    DECLARE_AND_DEFINE_DOUBLE_OPERATOR___(/)
    #undef DECLARE_AND_DEFINE_DOUBLE_OPERATOR___



private:
	double val_;
    bool has_got_;
};





#endif
