# tokenize

It will tokenize string, vector, etc. into any container which has std::inserter. Written without any reason or purpose. 

```c++

#include "tokenize.h"
#include <bits/stdc++.h>


template<typename T>
void print(const T &res)
{ std::cout<<res.size()<<"\n";
	for(const auto &str:res)
	{
		std::cout<<str<<"\t";
	}
	std::cout<<"\n";
}

void print(const std::vector<std::vector<std::string>> & res)
{ std::cout<<res.size()<<"\n";
	for(const auto &v:res)
	{
		for(const auto &str:v)
			std::cout<<str<<"\t";
		std::cout<<"===\n";
	}
	std::cout<<"\n";
}




int main()
{
	
	std::string source1= "something to split, something:well:cut,,,,    abolutely-useless-tokenizer";
	std::string source2= "ummagummanospitsfound";	
	std::string source3= "";
	std::string source4;
	std::string separators=" ,:-";
	bool allowEmptyEntry=true;
	
	std::vector<std::string> sourceVector {"alpha","b","beta","gamma"};
	std::vector<std::string> separatorsVector {"b"};

	print(tokenize<std::string> (source1,separators));
	print(tokenize<std::string> (source1,separators,allowEmptyEntry));
	print(tokenize<std::string,std::unordered_set> (source1,separators));
	print(tokenize<std::string,std::set> (source1,separators));
	print(tokenize<std::string> (source2,separators));
	print(tokenize<std::string,std::vector> (source3,separators));
	print(tokenize<std::string,std::vector> (source4,separators));
	print(tokenize<std::vector<std::string>,std::vector> (sourceVector,separatorsVector));
	
}
/*
Output:

Number of elements: 9
'something'	'to'	'split'	'something'	'well'	'cut'	'abolutely'	'useless'	'tokenizer'	
Number of elements: 17
'something'	'to'	'split'	''	'something'	'well'	'cut'	''	''	''	''	''	''	''	'abolutely'	'useless'	'tokenizer'	
Number of elements: 8
'tokenizer'	'useless'	'to'	'split'	'cut'	'something'	'well'	'abolutely'	
Number of elements: 8
'abolutely'	'cut'	'something'	'split'	'to'	'tokenizer'	'useless'	'well'	
Number of elements: 1
'ummagummanospitsfound'	
Number of elements: 0

Number of elements: 0

Number of elements: 2
'alpha'	
===
'beta'	'gamma'	
===



*/
