 //
 //  AdRoll.h
 //  AdRoll-iOS-SDK
 //
 //  Created by AdRoll.
 //  Copyright (c) 2014 AdRoll. All rights reserved.
 //

#import <Foundation/Foundation.h>
#import "AdRoll-Constants.h"


/**
 *  @abstract 
 *  Track clients and their events to later segment your AdRoll campaigns.
 *  
 *  @par
 *  AdRoll is the world’s largest retargeting platform with over 10,000 active advertisers worldwide. The company’s
 *  innovative and easy-to-use marketing platform enable brands of all sizes to create personalized ad campaigns based
 *  on their own website data, ensuring maximum return on online advertising spend. With a 97% customer rate, AdRoll 
 *  provides unmatched transparency and reach across the largest display inventory sources, including Google AdX and 
 *  Facebook Exchange.
 */
@interface AdRoll : NSObject

#pragma mark - Initialization

/**
 *  Initialize the service using your AdRoll's Advertisable and Pixel identifiers.
 *  
 *  @warning The Advertisable and Pixel Ids need to be initialized in the App Delegate method 
 *           \c application:didFinishLaunchingWithOptions: before any event is logged.
 *
 *  @param advertisableId the id of the advertisable
 *  @param pixelId        the id of the pixel
 *
 */
+ (void)initializeWithAdvertisableId:(NSString *)advertisableId pixelId:(NSString *)pixelId;


#pragma mark - User Details

/**
 *  A unique id for the user in your app. (typically this is the ID for the user in your database)
 *  @param userId The string name for the user id, nil to clear
 */
+ (void)setUserId:(NSString *)userId;


/** 
 *  The user's email address.
 *  @param userEmail The user's email address, nil to clear
 */
+ (void)setUserEmail:(NSString *)userEmail;


/**
 *  The user's phone number.
 *  Phone numbers are E164 format (without +) Ex: 14151234567
 *  @param userPhoneNumber The user's email address or nil to clear
 */
+ (void)setUserPhoneNumber:(NSString *)userPhoneNumber;

/**
 *  Hash user data (userEmail, userPhone, userId) - if set user data will MD5 hashed.
 *  @param flag if YES user data will be hashed, clear text values will not be used. 
 */
+ (void)setHashUserData:(BOOL)flag;


#pragma mark - Logging Events

/**
 *  Log an application usage event with a given name
 *
 *  @param name The event name to be tracked (e.g. AdRollEventName.ProductViewed),
 *              or you can use a custom name (e.g @"awesome-event").
 *
 *  Example Usage: [ARPixel logEvent:AdRollEventName.Reservation];
 */
+ (void)logEvent:(NSString *)name;


/**
 *  Log an application usage event with a given name and properties
 *
 *  @param name         The event name to be tracked (e.g. AdRollEventName.ProductViewed),
 *                      or you can use a custom name (e.g @"awesome-event").
 *  @param properties   The set of properties associated to the event.
 *
 *  Example Usage: [ARPixel logEvent:AdRollEventName.Searched
 *                              properties:@{AdRollEventPropertySearchString : @"mens shoes"}];
 *
 */
+ (void)logEvent:(NSString *)name properties:(NSDictionary *)properties;


#pragma mark - Convenience Methods for Logging Events


/**
 *  A convenience method for logging when content/product is viewed
 *  Do not call this method for IAP events as they are automatically logged, (unless explicitly disabled)
 *
 *  Note: This method is equivalent to calling
 *  [ARPixel logEvent:AdRollEventName.ProductViewed properties:@{AdRollEventPropertyProductPrice : @(99.99),
 *                                                               AdRollEventPropertyCurrency : @"USD",
 *                                                               AdRollEventPropertyProductId : @"12345",
 *                                                               AdRollEventPropertyProductName : @"Phat Fixie",
 *                                                               AdRollEventPropertyProductType : @"bike"}];
 *
 *  If there are multiple different items view at one time, call logPurchase for each item type
 *
 *  @param price content/product cost, or 0 if no cost.
 *  @param currency 3 letter ISO-4217 currency code (eg. USD, EUR, GBP, AUD)
 *  @param productId any type of unique identifier such as SKU or EAN (EAN barcode preferred if available) or nil if none
 *  @param productName the name or description of the product e.g. @"XBuds Headphones" or nil if none
 *  @param productType eg. @"product", @"music", @"photo", @"video".
 *  @param properties additional properties associated with the purchase, or nil if none.
 *
 */
+ (void)logEventProductViewed:(double)price
                     currency:(NSString *)currency
                    productId:(NSString *)productId
                  productName:(NSString *)productName
                  productType:(NSString *)productType
                   properties:(NSDictionary *)properties;


/**
 *  A convenience method for logging when an item has been added to a cart.
 *  If there are multiple items added to a cart, call logAddToCart for each item
 *
 *  If there are multiple different items added to a cart, logAddToCart for each item type
 *
 *  @param price content/product cost, or 0 if no cost.
 *  @param quantity the number of items added.
 *  @param currency 3 letter ISO-4217 currency code (eg. USD, EUR, GBP, AUD)
 *  @param productId any type of unique identifier such as SKU or EAN (EAN barcode preferred if available) or nil if none
 *  @param productName the name or description of the product e.g. @"XBuds Headphones" or nil if none
 *  @param productType eg. @"product", @"music", @"photo", @"video".
 *  @param properties additional properties associated with the purchase, or nil if none.
 */
+ (void)logEventAddedToCart:(double)price
                   quantity:(int)quantity
                   currency:(NSString *)currency
                  productId:(NSString *)productId
                productName:(NSString *)productName
                productType:(NSString *)productType
                 properties:(NSDictionary *)properties;


/**
 *  A convenience method for logging a non-IAP purchase.
 *  Do not call this method for IAP events as they are automatically logged, (unless explicitly disabled)
 *
 *  If there are multiple items purchased at one time, call logPurchase for each item.
 *  @param price content/product cost, or 0 if no cost.
 *  @param quantity the number of items added.
 *  @param currency 3 letter ISO-4217 currency code (eg. USD, EUR, GBP, AUD)
 *  @param productId any type of unique identifier such as SKU or EAN (EAN barcode preferred if available) or nil if none
 *  @param productName the name or description of the product e.g. @"XBuds Headphones" or nil if none
 *  @param productType eg. @"product", @"music", @"photo", @"video".
 *  @param properties additional properties associated with the purchase, or nil if none.
 */
+ (void)logEventPurchase:(double)price
                quantity:(int)quantity
                currency:(NSString *)currency
               productId:(NSString *)productId
             productName:(NSString *)productName
             productType:(NSString *)productType
              properties:(NSDictionary *)properties;


#pragma mark - In App Purchases

/**
 * IAP events are automatically logged to simplify segmenting. 
 * Call this method to disable this feature.
 */
+ (void)disableAutomaticInAppPurchaseEventLogging;


#pragma mark Developer hints

/**
 * Use the static methods provided instead of instantiating this class.
 */
- (instancetype)init __attribute__((unavailable("Use the designated initializer instead.")));


#if DEBUG
/**
 * Verbose messages are useful for debugging the integration of the AdRoll SDK in your application.
 *
 * Error messages and warnings will always be logged to STDOUT (the Console). Enabling verbose messages success messages
 * and status information will also be output so you can verify the integration.
 *
 * Verbose messages are disabled by default.
 *
 * @warning This method is only available in debug mode. Wrap the call in \c #if \c DEBUG \c … \c #endif preporcessor
 *          directives, or delete it after validating the integration.
 *
 * @param   enabled   \c YES to enable verbose messages.
 */
+ (void)setVerboseLogging:(BOOL)enabled;
#endif

@end
