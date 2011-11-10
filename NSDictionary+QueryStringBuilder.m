//
//  NSDictionary+QueryStringBuilder.m
//  CouchCocoa
//
//  Created by Kevin Smithson on 9/19/11.
//  Copyright (c) 2011 Couchbase, Inc. All rights reserved.
//

#import "NSDictionary+QueryStringBuilder.h"

NSString * escapeString(NSString *string) {
    NSString *s = (NSString *)CFURLCreateStringByAddingPercentEscapes(NULL,
                                                                      (CFStringRef)string,
                                                                      NULL,
                                                                      (CFStringRef)@"!*'\"();:@&=+$,/?%#[]% ",
                                                                      kCFStringEncodingUTF8);
    return [s autorelease];
    
}

@implementation NSDictionary (QueryStringBuilder)
- (NSString *)queryString
{
    NSMutableString *queryString = nil;
    NSArray *keys = [self allKeys];
    
    if ([keys count] > 0) {
        for (id key in keys) {
            id value = [self objectForKey:key];
            if (nil == queryString) {
                queryString = [[[NSMutableString alloc] init] autorelease];
                [queryString appendFormat:@"?"];
            } else {
                [queryString appendFormat:@"&"];
            }
            
            if (nil != key && nil != value) {
                [queryString appendFormat:@"%@=%@", escapeString(key), [value isKindOfClass:[NSString class]] ? [NSString stringWithFormat:@"\"%@\"", escapeString(value)] : escapeString(value)];
            } else if (nil != key) {
                [queryString appendFormat:@"%@", escapeString(key)];
            }
        }
    }
    
    return queryString;
}
@end