#pragma once

#include <vector>
#include <algorithm>

template<typename ContainerType>
using ConstIterType=typename ContainerType::const_iterator;

template<typename SrcContType, template <typename ...> class ContainerType=std::vector>
ContainerType<SrcContType>  tokenize(const SrcContType &source,const SrcContType &separators, bool allowEmpty=false)
{
	ContainerType<SrcContType>  retVal;
	auto inserter = std::inserter(retVal, retVal.end());// all standard containers but forward_list !!	
	
	auto start=std::begin(source);
	auto end=std::end(source);
	auto separatorStart=std::begin(separators);
	auto separatorEnd=std::end(separators);

	ConstIterType<SrcContType> next;
	auto prev=start;	
	do 
	{
		next=std::find_first_of(prev,end,separatorStart,separatorEnd);	
		if(allowEmpty||(next>prev && prev<end)) 
			++(*inserter) = SrcContType(prev,next);			
		prev= next+1;		
	}while (next!=end);
	
	return retVal;
}
