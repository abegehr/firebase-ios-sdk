/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// TODO: Should not be public after Auth.swift.

#import <TargetConditionals.h>
#if TARGET_OS_IOS

#import <UIKit/UIKit.h>

@class FIRAuthWebViewController;
@protocol FIRAuthUIDelegate;

/** @typedef FIRAuthURLPresentationCompletion
    @brief The type of block invoked when the URLPresentation completes.
    @param callbackURL The callback URL if the presentation ends with a matching callback.
    @param error The error if the presentation fails to start or ends with an error.
 */
typedef void (^FIRAuthURLPresentationCompletion)(NSURL *_Nullable callbackURL,
                                                 NSError *_Nullable error);

/** @typedef FIRAuthCallbackMatcher
    @brief The type of block invoked for checking whether a callback URL matches.
    @param callbackURL The callback URL to check for match.
    @return Whether or not the specific callback URL matches or not.
 */
typedef BOOL (^FIRAuthURLCallbackMatcher)(NSURL *_Nullable callbackURL);

NS_ASSUME_NONNULL_BEGIN

/** @protocol FIRAuthWebViewControllerDelegate
    @brief Defines a delegate for FIRAuthWebViewController
 */
@protocol FIRAuthWebViewControllerDelegate <NSObject>

/** @fn webViewController:canHandleURL:
    @brief Determines if a URL should be handled by the delegate.
    @param URL The URL to handle.
    @return Whether the URL could be handled or not.
 */
- (BOOL)webViewController:(FIRAuthWebViewController *)webViewController canHandleURL:(NSURL *)URL;

/** @fn webViewControllerDidCancel:
    @brief Notifies the delegate that the web view controller is being cancelled by the user.
    @param webViewController The web view controller in question.
 */
- (void)webViewControllerDidCancel:(FIRAuthWebViewController *)webViewController;

/** @fn webViewController:didFailWithError:
    @brief Notifies the delegate that the web view controller failed to load a page.
    @param webViewController The web view controller in question.
    @param error The error that has occurred.
 */
- (void)webViewController:(FIRAuthWebViewController *)webViewController
         didFailWithError:(NSError *)error;

/** @fn presentURL:UIDelegate:callbackMatcher:completion:
    @brief Presents an URL to interact with user.
    @param URL The URL to present.
    @param UIDelegate The UI delegate to present view controller.
    @param completion A block to be called either synchronously if the presentation fails to start,
        or asynchronously in future on an unspecified thread once the presentation finishes.
 */
- (void)presentURL:(NSURL *)URL
         UIDelegate:(nullable id<FIRAuthUIDelegate>)UIDelegate
    callbackMatcher:(FIRAuthURLCallbackMatcher)callbackMatcher
         completion:(FIRAuthURLPresentationCompletion)completion;

@end

NS_ASSUME_NONNULL_END

#endif
