/* Utils.h
 *
 * Copyright (C) 2012  Belledonne Comunications, Grenoble, France
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef LINPHONE_UTILS_H
#define LINPHONE_UTILS_H

#define DYNAMIC_CAST(x, cls)                        \
 ({                                                 \
    cls *inst_ = (cls *)(x);                        \
    [inst_ isKindOfClass:[cls class]]? inst_ : nil; \
 })

#import <ortp/ortp.h>

@interface LinphoneLogger : NSObject {

}

+ (void)log:(OrtpLogLevel)severity file:(const char *)file line:(int)line format:(NSString *)format, ...;
void linphone_iphone_log_handler(const char *domain, OrtpLogLevel lev, const char *fmt, va_list args);
@end

@interface LinphoneUtils : NSObject {

}

+ (BOOL)findAndResignFirstResponder:(UIView*)view;
+ (void)adjustFontSize:(UIView*)view mult:(float)mult;
+ (void)buttonFixStates:(UIButton*)button;
+ (void)buttonFixStatesForTabs:(UIButton*)button;
+ (void)buttonMultiViewAddAttributes:(NSMutableDictionary*)attributes button:(UIButton*)button;
+ (void)buttonMultiViewApplyAttributes:(NSDictionary*)attributes button:(UIButton*)button;
+ (NSString *)deviceName;
+ (NSString*)phoneNumberFromURI:(NSString*)sipURI;
+ (BOOL)isInternationalPhoneNumber:(NSString*)phoneNumber;
+ (NSDictionary*)normalizeServerDictionary:(NSDictionary*)jsonDictionary;
+ (NSArray*)normalizeServerArray:(NSArray*)arrayOfObjects;
+ (NSString*) normalizeServerString:(NSString*)value;
+ (NSString*)cardDAVRealmName;
+ (NSString*)cardDAVServerPath;

@end

@interface NSNumber (HumanReadableSize)

- (NSString*)toHumanReadableSize;

@end

#define LOGV(level, ...) [LinphoneLogger log:level file:__FILE__ line:__LINE__ format:__VA_ARGS__]
#define LOGD(...) LOGV(ORTP_DEBUG, __VA_ARGS__)
#define LOGI(...) LOGV(ORTP_MESSAGE, __VA_ARGS__)
#define LOGW(...) LOGV(ORTP_WARNING, __VA_ARGS__)
#define LOGE(...) LOGV(ORTP_ERROR, __VA_ARGS__)
#define LOGF(...) LOGV(ORTP_FATAL, __VA_ARGS__)

#endif

@interface NSString(md5)

- (NSString *)md5;

@end
