//  Copyright (c) 2013 Rob Rix. All rights reserved.

#import <RXCollections/RXEnumerator.h>

@interface RXFastEnumerator : NSEnumerator <RXEnumerator>

-(instancetype)initWithEnumeration:(id<NSObject, NSFastEnumeration>)enumeration;

@end


static inline id<RXEnumerator> RXEnumeratorWithEnumeration(id<NSObject, NSFastEnumeration> enumeration) {
	return [enumeration conformsToProtocol:@protocol(RXEnumerator)]?
		(id<RXEnumerator>)enumeration
	:	[[RXFastEnumerator alloc] initWithEnumeration:enumeration];
	
}
