//
// Copyright © 2020 osy. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import "UTMInputOutput.h"
#import "UTMSpiceIODelegate.h"
#if defined(WITH_QEMU_TCI)
@import CocoaSpiceNoUsb;
#else
@import CocoaSpice;
#endif

@class UTMQemuConfiguration;

NS_ASSUME_NONNULL_BEGIN

@interface UTMSpiceIO : NSObject<UTMInputOutput, CSConnectionDelegate>

@property (nonatomic, readonly, nonnull) UTMQemuConfiguration* configuration;
@property (nonatomic, readonly, nullable) CSDisplayMetal *primaryDisplay;
@property (nonatomic, readonly, nullable) CSInput *primaryInput;
#if !defined(WITH_QEMU_TCI)
@property (nonatomic, readonly, nullable) CSUSBManager *primaryUsbManager;
#endif
@property (nonatomic, weak, nullable) id<UTMSpiceIODelegate> delegate;
@property (nonatomic, readonly) BOOL isConnected;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithConfiguration: (UTMQemuConfiguration*) configuration NS_DESIGNATED_INITIALIZER;
- (void)changeSharedDirectory:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
