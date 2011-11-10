//
//  NSDictionary+QueryStringBuilder.h
//  CouchCocoa
//
//  Created by Kevin Smithson on 9/19/11.
//  Copyright (c) 2011 Couchbase, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (QueryStringBuilder)

- (NSString *)queryString;

@end

NSString * escapeString(NSString *string);