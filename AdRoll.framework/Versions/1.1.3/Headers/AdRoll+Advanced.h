//
//  AdRoll+Advanced.h
//  AdRoll-iOS-SDK
//
//  Created by AdRoll.
//  Copyright (c) 2014 AdRoll. All rights reserved.
//

#import <AdRoll/AdRoll.h>

@interface AdRoll (DeepLinking)

/**
 *  Initialize the service using your AdRoll's Advertisable and Pixel identifiers.
 *
 *  @warning    Setting the default scheme is advanced functionality and discouraged initially. We will disclose this
 *              method to developers when necessary accompanied by additional documentation and limitations.
 *
 *  @param advertisableId the id of the advertisable
 *  @param pixelId        the id of the pixel
 *  @param scheme         an optional schema can be used to identify your app when building segments.
 *                        The provided schema must be a valid URL scheme. See http://www.ietf.org/rfc/rfc2396.txt
 */
+ (void)initializeWithAdvertisableId:(NSString *)advertisableId pixelId:(NSString *)pixelId scheme:(NSString *)scheme;

@end


@interface AdRoll (NavigationLogging)

/**
 *  @abstract Let the current application location to the given page. This method will log a page view event with the 
 *  new location.
 *
 *  @par The given location will be used as the referrer for the following events logged.
 *
 *  @param url          an RFC 2396 compliant url (e.g. tld.test.your-app://page/in/the/app)
 */
+ (void)setPageViewWithURL:(NSURL *)url;


/**
 *  @abstract Let the current application location to the given page. This method will log a page view event with the
 *  new location.
 *
 *  @par The given location will be used as the referrer for the following events logged.
 *
 *  @param url          an RFC 2396 compliant url (e.g. tld.test.your-app://page/in/the/app)
 *  @param properties   additional properties
 */
+ (void)setPageViewWithURL:(NSURL *)url properties:(NSDictionary *)properties;

@end
