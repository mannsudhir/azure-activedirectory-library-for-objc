// Copyright © Microsoft Open Technologies, Inc.
//
// All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS
// OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
// ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A
// PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
//
// See the Apache License, Version 2.0 for the specific language
// governing permissions and limitations under the License.

@class ADTokenCacheItem;

/* Internally accessible methods.*/
@interface ADAuthenticationResult (Internal)

/*! Creates a result from a user or request cancellation condition, with/without correlation id. */
+ (ADAuthenticationResult*)resultFromCancellation;
+ (ADAuthenticationResult*)resultFromCancellation:(NSUUID*)correlationId;

/*! Creates an authentication result from an error condition, with/without correlation id. */
+ (ADAuthenticationResult*)resultFromError:(ADAuthenticationError*)error;
+ (ADAuthenticationResult*)resultFromError:(ADAuthenticationError*)error
                             correlationId:(NSUUID*)correlationId;

+ (ADAuthenticationResult*)resultFromParameterError:(NSString*)details;
+ (ADAuthenticationResult*)resultFromParameterError:(NSString*)details
                                      correlationId:(NSUUID*)correlationId;

/*! Creates an instance of the result from a pre-setup token cache store item */
+ (ADAuthenticationResult*)resultFromTokenCacheStoreItem:(ADTokenCacheItem*)item
                               multiResourceRefreshToken:(BOOL)multiResourceRefreshToken
                                           correlationId:(NSUUID*)correlationId;

/*! Creates an authentication result from broker response, which can be with/without correlation id. */
+ (ADAuthenticationResult*)resultFromBrokerResponse:(NSDictionary*)response;

@end
