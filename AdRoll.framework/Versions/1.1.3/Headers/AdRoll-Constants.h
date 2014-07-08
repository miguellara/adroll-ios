//
//  AdRoll-Constants.h
//  AdRoll-iOS-SDK
//
//  Created by AdRoll.
//  Copyright (c) 2014 AdRoll. All rights reserved.
//

#ifndef ARPixel_AdRoll_Constants_h
#define ARPixel_AdRoll_Constants_h

struct AdRollEventName {
    
    // Common Events - System events e.g. Background/Foreground, are automatically logged
    
    /*! User has registered/createdloggedin to an account */
    __unsafe_unretained NSString *const Registered;
    /*! User has viewed a product or content */
    __unsafe_unretained NSString *const ProductViewed;
    /*! User has searched or selected a specific category */
    __unsafe_unretained NSString *const Searched;
    /*! User has rated/liked an item. */
    __unsafe_unretained NSString *const Rated;
    /*! User has completed an initial action in the app. e.g watched a tutorial or demo. */
    __unsafe_unretained NSString *const TutorialCompleted;
    
    // E-commerce Events - IAP events are automatically logged unless explicitly disabled
    
    /*! User has added an item to their cart. */
    __unsafe_unretained NSString *const AddedToCart;
    /*! User has added an item to their wishlist. */
    __unsafe_unretained NSString *const AddedToWishlist;
    /*! User has entered their payment info. */
    __unsafe_unretained NSString *const AddedPaymentDetails;
    /*! User has purchased a product/content. (convience method logPurchase available) */
    __unsafe_unretained NSString *const Purchase;
    /*! User has made a reservation */
    __unsafe_unretained NSString *const Reservation;
    
    // Gaming Events - Note: IAP events are automatically logged
    
    /*! User has reached a certain level or achievement */
    __unsafe_unretained NSString *const LevelReached;
    /*! User has reached a certain level or achievement */
    __unsafe_unretained NSString *const AchievementUnlocked;
    /*! User has used credits. */
    __unsafe_unretained NSString *const CreditsSpent;
    
    // Viral Events
    
    /*! User has shared content or the app via text/email/fb/twitter/other */
    __unsafe_unretained NSString *const Shared;
    /*! User has invited a friend(s) to share content or the app via text/email/fb/twitter/other */
    __unsafe_unretained NSString *const Invited;
    
    
};
extern const struct AdRollEventName AdRollEventName;


// Event property keys for use with LogEvent (You can specify custom properties if required)

/*! Product Id, any type of unique identifier such as SKU or EAN (EAN barcode preferred if available) */
extern NSString *const AdRollEventPropertyProductId;

/*! Product Type eg. @"product", @"music", @"photo", @"video". */
extern NSString *const AdRollEventPropertyProductType;

/*! Product Name, the name or description of the product/content. e.g. @"XBuds Headphones" */
extern NSString *const AdRollEventPropertyProductName;

/*! Product Price e.g. 1.99 Use with AREventParamNameCurrency */
extern NSString *const AdRollEventPropertyProductPrice;

/*! Conversion value for a purchase or subscription event */
extern NSString *const AdRollEventPropertyConversionValue;

/*! Currency Code (ISO-4217), eg. USD, EUR, GBP, AUD */
extern NSString *const AdRollEventPropertyCurrency;

/*! Level to specify the level achieved in a "LevelReached" event. */
extern NSString *const AdRollEventPropertyLevel;

/*! Number of items of product/content */
extern NSString *const AdRollEventPropertyQuantity;

/*! Search string or category. */
extern NSString *const AdRollEventPropertySearchString;

/*! Bundle identifier of the source application */
extern NSString *const AdRollEventPropertySourceApplication;

#endif
