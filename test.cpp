
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <iterator>

#include "tracer.tcc"
using namespace tracer;

int main(){
	const	char ch[] = "There, by the billows desolate,";
	std::cout << std::setw(FIELD) << "sizeof X:" << (sizeof(X)) << std::endl;
	std::cout << std::setw(FIELD) << "sizeof std::basic_string<X>:" << (sizeof(std::basic_string<X>)) << std::endl;
	std::cout << std::setw(FIELD) << "sizeof std::string:" << (sizeof (std::string)) << std::endl;
	std::cout << std::setw(FIELD) << "typedef std::basic_string<X> xs;" << std::endl;
std::ostream_iterator<char> out_it (std::cout,", ");
	X::head();
	X::show("{");
{	//single operations
	X a;
	X::show("X a;");
	a = '1';
	X::show("a = '1';");
	X b = a;
	X::show("X b = a;");
	X c(a);
	X::show("X c(a);");
	c('e');
	X::show("c('e');");
	c = b;
	X::show("c = b;");
	(c = b) = 'e';
	X::show("(c=b)='e';");
	c < b;
	X::show("a < b;");
	a == b;
	X::show("a == b;");
	#if __cplusplus > 199711L
	[](X y)->X{return y.v;}(b);
	X::show("[](X y)->X{return y.v;}(b);");
	a = [](X y)->X{return y;}(b);
	X::show("a = [](X y)->X{return y;}(b);");
	#endif
}
	X::show("}");
	std::cout << std::endl;

//arrays of X
{
	X::show("{");
	X a[10];
	X::show("X a[10];");
	std::copy(ch,ch+10,a);
	X::show("std::copy(ch,ch+10,a);");
	X b[10] = { 'o', 'b' };	
	X::show("X b[10] = {'o'};");
	std::copy(a,a+10,b);
	X::show("std::copy(a,a+10,b);");
}
	X::show("}");
	std::cout << std::endl;

//single strings
//typedef std::basic_string<X> xs;
{
	X::head();
	X::show("{");
	const xs s1;
	X::show("const xs s1;");
	xs s2(s1);
	X::show("xs s2(s1);");
	xs s3 = s1;
	X::show("xs s3 = s1;");
}
	X::show("}");
	std::cout << std::endl;
/*
There, by the billows desolate, 
He  stood, with mighty thoughts elate, 
And gazed; but in the distance only 
A sorry skiff on the broad spate
*/

{
	X::head();
	X::show("{");
	xs s1((X*)"1234567890");
	X::show("xs s1((X*)\"1234567890\");");
	xs s2((X*)"1234567890",7);
	X::show("xs s2((X*)\"1234567890\",7);");
	xs s3(10,'a');
	X::show("xs s3(10,'a');");
	xs s4(s1.begin(), s1.begin()+7);
	X::show("xs s4(s1.begin(), s1.begin()+7);");
	xs s5(s2);
	X::show("xs s5(s2);");
	s5[0] = 'a';
	X::show("s5[0]='a';");
	xs s6(s1);
	X::show("xs s6(s1);");
	s6[0] = 'a';
	X::show("s6[0]='a';");
	xs s7(s1,1,5);
	X::show("xs s7(s1,1,5);");
	#if __cplusplus > 199711L
	xs s8 = []()->xs{xs a((X*)"ololo");return a;}();
	X::show("xs s8=[]()->xs{xs a((X*)\"lol\");return a;}();");
	std::cout << (char*)s8.data() << std::endl;
	#endif
	xs s9((X*)"1234567890");
	X::show("xs s9((X*)\"1234567890\");");
	X n= s9[0];
	X::show("X n = s9[0];");

//----------------------------------------------------------------

	int a = s1.size();
	X::show("int a = s1.size();");
	s1.resize(100);
	X::show("s1.resize(100);");
	s2.reserve(100);
	X::show("s2.reserve(100);");
	s1.erase();
	X::show("s1.erase();");
	s1.insert(0,s2);
	X::show("s1.insert(0,s2);");
	s1.insert(0,s2,2,4);
	X::show("s1.insert(0,s2,2,4);");

//----------------------------------------------------------------

	X::show("s3 = s1;");
	s3 == s1;	
	X::show("s3 == s1;");
	s2 != s1;
	X::show("s2 != s1;");
	s1 > s2;
	X::show("s1 > s2;");
        std::equal(s1.begin(),s1.end(),s2.begin());
        X::show("equal(s1.begin(),s1.end(),s2.begin());");
        std::mismatch(s1.begin(),s1.end(),s2.begin());
        X::show("mismatch(s1.begin(),s1.end(),s2.begin());");
        
        std::copy(s1.begin(),s1.end(),out_it);
        std::cout << std::endl; 
        X::show("copy(s1.begin(),s1.end(),out_it);");
        
        std::sort(s1.begin(),s1.end());
        X::show("std::sort(s1.begin(),s1.end());");
        std::swap(s1,s2);
        X::show("std::swap(s1,s2);");
        s3 = s1 + s2;
        X::show("s3 = s1 + s2;");
        s1 + s2;        
        X::show("s1 + s2;");
        s3 += s1;       
        X::show("s3 += s1;");
        s3.substr(10);  
        X::show("s3.substr(10);");
        s4 = s3.substr(10);     
        X::show("s4 = s3.substr(10);");
        s4 = s3.find(s2);
        X::show("s4 = s3.find(s2);");

}
	X::show("}");
	std::cout << std::endl;
	return 0;
}
