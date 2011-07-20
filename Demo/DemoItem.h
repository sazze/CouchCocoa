//
//  DemoItem.h
//  CouchCocoa
//
//  Created by Jens Alfke on 6/1/11.
//  Copyright 2011 Couchbase, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class CouchDatabase, CouchDocument;


/** A simple generic model class that wraps a CouchDocument, making its properties available
    for key-value coding/observing. UI controls can then be bound to these properties,
    and changes they make will be saved to the database automatically. */
@interface DemoItem : NSObject
{
    CouchDocument* _document;
    NSDictionary* _properties;
    NSMutableDictionary* _changedProperties;
    CFAbsoluteTime _changedTime;
}

/** Returns the DemoItem associated with a CouchDocument, or creates & assigns one if necessary. */
+ (DemoItem*) itemForDocument: (CouchDocument*)document;

/** Creates a new "untitled" item with no document yet.
    Setting its -database property will cause it to create and save a CouchDocument. */
- (id) init;

/** The document this item is associated with. Will be nil if it's new and unsaved. */
@property (readonly, retain) CouchDocument* document;

/** The database the item's document belongs to.
    Setting this property will assign the item to a database, creating a document.
    Setting it to nil will remove its document from its database. */
@property (retain) CouchDatabase* database;

/** Writes any changes made by KVC to the database. This happens automatically after changes are
    made, so it doesn't need to be called explicitly. */
- (void) save;

- (void) markExternallyChanged;

@property (readonly) NSTimeInterval timeSinceExternallyChanged;

@end