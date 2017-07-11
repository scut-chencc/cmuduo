#include <iostream>
#include <boost/static_assert.hpp>

class Timestamp
{
	private:
	int64_t microSecondSinceEpoch_;	 
};
BOOST_STATIC_ASSERT( sizeof( Timestamp)  == sizeof( int64_t) ) ;
int main( )
{
	return 0;
}
