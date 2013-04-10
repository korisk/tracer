#ifndef __TRACER_FOR_STRING__
#define __TRACER_FOR_STRING__

#include <iostream>
#include <string>
#include <iomanip>
#include <iterator>

#define habr 0
#if habr == 1
#	define delimitera  	"</td><td>"
#	define delimiterb  	"</td><td>"
#	define fin 		"</td></tr>"
#	define start 		"<tr><td>"
#	define finh 		"</th></tr>"
#	define starth 		"<tr><th>"
#	define delimiterh  	"</th><th>"
#	define FIELD		0
#else
#	define delimitera  	"   "
#	define delimiterb  	"  "
#	define fin 		""
#	define start 		""
#	define finh 		" "
#	define starth 		" "
#	define delimiterh  	" "
#	define FIELD		41
#endif

namespace tracer{

struct X{
	char v; //value

	X():v(){ X::c[ctor]++; };
	X(char x):v(x){ X::c[ctor]++; };
	X(X const& x):v(x.v) { X::c[copy]++; };
	~X(){ X::c[dtor]++; };

	X& operator=(X const& x) { X::c[assgn]++; v=x.v; return *this; };
	X& operator=(char x) { X::c[assgn]++; v = x;   return *this; };
	X& operator()(char x) { X::c[cast]++; v = x;   return *this; };// X a = X('c');
	operator char() const { X::c[cast]++; return v; };	       // char x = a;
	bool operator==( X const & x) const { X::c[eql]++; return v == x.v; };
	bool operator==( char x) const { X::c[eql]++; return v == x; };
	bool operator<( X const& x) const { X::c[lss]++; return v < x.v; };	
	bool operator<( int x) const { X::c[lss]++; return v < x; };	


	enum { ctor=0, copy, assgn, dtor, lss, eql, cast, last };	
	static int c[]; //counters
	static ::std::string n[]; //names of the counters
	static void show(const ::std::string &title, const ::std::string& end);
	static void head(const ::std::string &header);

};
void X::show(const ::std::string &title = " ", const ::std::string &end=""){
	::std::ostream_iterator<int> out_it (::std::cout, delimitera );
	::std::cout << start << ::std::setw(FIELD) << title << delimiterb;
	::std::copy(c,c+last,out_it);	
	::std::cout << fin << ::std::endl;
	::std::fill(c,c+last,0);	
};
void X::head(const ::std::string &header = ""){
	::std::ostream_iterator< ::std::string > out_it (::std::cout,delimiterh);
	::std::cout  << ::std::setw(FIELD) << header << ::std::endl; 
	::std::cout << starth  << ::std::setw(FIELD) << "operation" << delimiterh; 
	::std::copy(n,n+last,out_it);	
	::std::cout<< finh << ::std::endl;
};
int X::c[X::last] = {0};
::std::string X::n[] = { "ctor", "copy", "assgn", "dtor", "lss", "eql", "cast", "last" };	


typedef ::std::basic_string<X> xs;

::std::ostream& operator<<(::std::ostream& out, xs &dat) { out << (char*)(dat.data()); return out; }
//X * operator X*(const char* dat){ return (X*)(dat); }
}
#endif
