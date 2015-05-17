//
//  StringsHandler.h
//  LocalizationManager
//
//  Created by Francesca Corsini on 15/05/15.
//  Copyright (c) 2015 Francesca Corsini. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^SuccessBlock)();
typedef void(^FailedBlock)();


@interface StringsHandler : NSObject
{
    // blocks
    SuccessBlock successBlock;
    FailedBlock failedBlock;
}

// the array with the strings from the master .strings file
@property (nonatomic, strong) NSMutableArray *masterStrings;

// the array with the strings from the secondary .strings file
@property (nonatomic, strong) NSMutableArray *secondaryStrings;

// the array with all the strings from 2 .strings file
@property (nonatomic, strong) NSMutableArray *mergedStrings;

// the array with only the differences between the 2 .strings  file
@property (nonatomic, strong) NSMutableArray *diffStrings;

// init
+ (instancetype)sharedInstance;

// save .strings
- (void)saveStrings:(NSString*)strings isDiff:(BOOL)isDiff success:(SuccessBlock)success failed:(FailedBlock)failed;

// diff .strings
- (void)diffStringsWithSuccess:(SuccessBlock)success failed:(FailedBlock)failed;

// merge .strings
- (void)mergeStringsWithSuccess:(SuccessBlock)success failed:(FailedBlock)failed;

// parsing .strings
- (NSAttributedString*)parseArrayToAttributeString:(NSArray*)array;
- (NSString*)parseArrayToStrings:(NSArray*)array;
- (void)parseMasterStrings:(NSString*)strings;
- (void)parseSecondaryStrings:(NSString*)strings;

@end
