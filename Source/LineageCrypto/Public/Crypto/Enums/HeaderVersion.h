#ifndef H_HEADER_VERSION
#define H_HEADER_VERSION
/**
*  Avoid using strongly typed enum here,
 * To be able to use type casting to `int`.
 */
enum EHeaderVersion
{
	INVALID = -1,
	NOT_IMPL = 0,
	VER_413 = 413
	
};

#endif // H_HEADER_VERSION
