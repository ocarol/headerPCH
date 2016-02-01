//
//  CommonHeader.h
//
#import "AppDelegate.h"

// debug 时请求生产环境数据 注释：测试服务器，反之正式环境
//#define IS_RELEASE_URL 1

// *********************************** 信息显示 ***********************************
#define ErrorMessage @"网络繁忙请稍后再试"
#define Alert(msg) [[[UIAlertView alloc] initWithTitle:@"" message:(msg) delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil,nil] show]

// *********************************** 数据存储与读取 ***********************************
// 偏好设置
#define Defaults [NSUserDefaults standardUserDefaults]
// 获取沙河下的路径
#define DOCUMENTS_FOLDER [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

#define MydocPath NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0]
#define filePath(s) [MydocPath stringByAppendingPathComponent:s]

// 保存到plist文件
#define WriteToPlist(dic,s) [dic writeToFile:filePath(s) atomically:YES];
// 读取plist文件到字典
#define ReadToPlist(s) [[[NSMutableDictionary alloc] initWithContentsOfFile:filePath(s)] mutableCopy]


// *********************************** 适配 ***********************************
// 计算文本的尺寸
#define textSize(text, fontSize, width) [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:fontSize]} context:nil].size;

#define textSize1(text, font, width) [text boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:font} context:nil].size;

#define textSize_IOS6 (text, font , width) [text sizeWithFont:font constrainedToSize:CGSizeMake(width, MAXFLOAT)];

// 计算文本的尺寸
#define textSizeFont(text, fontSizeFont, width, height) [text boundingRectWithSize:CGSizeMake(width, height) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:fontSizeFont} context:nil].size;

#define kDataManager [HACDataManager sharedInstance]

// 颜色
#define UIColorFromRGB(rgbValue)   [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0f green:((float)((rgbValue & 0xFF00) >> 8))/255.0f blue:((float)(rgbValue & 0xFF))/255.0f alpha:1.0f]
#define UIColorWithRGBA(r,g,b,a)   [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define Color(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define ColorA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]
#define ColorI(c) [UIColor colorWithRed:((c>>16)&0xff)/255.0 green:((c>>8)&0xff)/255.0 blue:(c&0xff)/255.0 alpha:1.0] // ColorI(0xbfbfbf)
#define ColorGray(f) [UIColor colorWithWhite:f/255.0 alpha:1.0]
// 随机色
#define RandomColor [UIColor colorWithRed:arc4random_uniform(256) / 255.0 green:arc4random_uniform(256) / 255.0 blue:arc4random_uniform(256) / 255.0 alpha:1]

// font
#define FontMainScore(s) [UIFont fontWithName:@"Avenir-Light" size:s]
#define Font(s) (IOS9 ? [UIFont systemFontOfSize:s] : [UIFont fontWithName:@"STHeitiSC-Light" size:s]) // San Francisco
#define FontBold(s) (IOS9 ? [UIFont boldSystemFontOfSize:s] : [UIFont fontWithName:@"STHeitiSC-Medium" size:s])
#define FontNum(s) [UIFont fontWithName:@"Avenir-Light" size:s]
//方正黑体简体字体定义
#define FONT_FZ(f) [UIFont fontWithName:@"FZHTJW--GB1-0" size:f]

// 4ihch字体
#define	FONT_4INCH_ADAPTED_WIDTH(s) Font(s)

#define	FONT_4INCH_SCALE_ADAPTED_WIDTH(s) FONT_ADAPTED_WIDTH(s/0.77294686f)

#define	FONTBOLD_4INCH_ADAPTED_WIDTH(s) FONTBOLD_ADAPTED_WIDTH(s/0.77294686f)

#define FONT_PLATE_NO(s) [UIFont fontWithName:@"Menlo-Regular" size:s]

// s=flash文件中字体大小/3.0f，也即经过屏幕密度处理后的大小
#define	FONT_ADAPTED_WIDTH(s) (IOS9 ? [UIFont systemFontOfSize:(int)round(s * SCREEN_WIDTH_RATIO55)] : [UIFont fontWithName:@"STHeitiSC-Light" size:(int)round(s * SCREEN_WIDTH_RATIO55)])
#define	FONTBOLD_ADAPTED_WIDTH(s) (IOS9 ? [UIFont boldSystemFontOfSize:(int)round(s * SCREEN_WIDTH_RATIO55)] : [UIFont fontWithName:@"STHeitiSC-Medium" size:(int)round(s * SCREEN_WIDTH_RATIO55)])
#define FONT_ADAPTED_NUM(s)	[UIFont fontWithName:@"Avenir-Light" size:(int)round(s * SCREEN_WIDTH_RATIO55)]

#define txtLength(t,f,l) [t getWidth:f limit:l]

// rect
#define KScreenWidth [[UIScreen mainScreen] bounds].size.width
#define KScreenHeight [[UIScreen mainScreen] bounds].size.height
#define KScreenHeight2 (IS_IPHONE_5?KScreenHeight:(KScreenHeight-20))
#define KContentHeight (KScreenHeight-20) // 568 vs 480
#define KScreenRect [[UIScreen mainScreen] bounds]
#define KContentRect CGRectMake(0.0, 20.0, KScreenWidth, KContentHeight)
#define KCameraBarHeight 40
#define kTabBarFrame CGRectMake(0.0, KContentHeight-80, 320.0, 80)

#define DOT_COORDINATE                  0.0f
#define STATUS_BAR_HEIGHT               20.0f
#define BAR_ITEM_WIDTH_HEIGHT           30.0f
#define NAVIGATION_BAR_HEIGHT           44.0f
#define TAB_TAB_HEIGHT                  49.0f
#define TABLE_VIEW_ROW_HEIGHT           NAVIGATION_BAR_HEIGHT
#define CONTENT_VIEW_HEIGHT_NO_TAB_BAR  (SCREEN_HEIGHT - STATUS_BAR_HEIGHT - NAVIGATION_BAR_HEIGHT)
#define CONTENT_VIEW_HEIGHT_TAB_BAR     (CONTENT_VIEW_HEIGHT_NO_TAB_BAR - TAB_TAB_HEIGHT)


// 检查系统版本
// 版本是否 == v
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
// 版本是否 > v
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
// 版本是否 >= v
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
// 版本是否 < v
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
// 版本是否 <= v
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

// iOS系统版本
#define iOS6  ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0)
#define IOS7 [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0
#define IOS8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define IOS9 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define iphone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_OS_5_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"5.0")
#define IS_OS_6_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"6.0")
#define IS_OS_7_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"7.0")
#define IS_OS_8_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"8.0")
#define IS_OS_9_OR_LATER                            SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(@"9.0")


#define IS_WIDESCREEN_5                            (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)568) < __DBL_EPSILON__)
#define IS_WIDESCREEN_6                            (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)667) < __DBL_EPSILON__)
#define IS_WIDESCREEN_6Plus                        (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)736) < __DBL_EPSILON__)
// 判断是真机还是模拟器
#define IS_IPHONE                                  ([[[UIDevice currentDevice] model] isEqualToString: @"iPhone"] || [[[UIDevice currentDevice] model] isEqualToString: @"iPhone Simulator"])
#define IS_IPOD                                    ([[[UIDevice currentDevice] model] isEqualToString: @"iPod touch"])
#define IS_PAD                                     (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE_5                                (IS_IPHONE && IS_WIDESCREEN_5)
#define IS_IPHONE_6                                (IS_IPHONE && IS_WIDESCREEN_6)
#define IS_IPHONE_6Plus                            (IS_IPHONE && IS_WIDESCREEN_6Plus)

// 手机型号
#define IS_IPHONE6_PLUS (KScreenWidth > 375)
#define IS_IPHONE6 (KScreenWidth > 320)
#define AutoSizeScaleX (KScreenHeight > 480 ? KScreenWidth/320 : 1.0)
#define AutoSizeScaleY (KScreenHeight > 480 ? KScreenHeight/568 : 1.0)
#define CGRectMakeCustom(x, y, width, height) CGRectMake(x * AutoSizeScaleX, y * AutoSizeScaleY, width * AutoSizeScaleX, height * AutoSizeScaleY)
#define CGSizeMakeCustom(width,height)  CGSizeMake(width * AutoSizeScaleX,height * AutoSizeScaleY)

#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define SYSTEM_VERSION_LESS_THAN(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending) // if(SYSTEM_VERSION_LESS_THAN(@"4.0")) ...

#define IS_IPHONE_5 (fabs((double)KScreenHeight-(double)568)<DBL_EPSILON)

// 屏幕尺寸
#define	IS_35_INCH_SCREEN	CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)
#define	IS_40_INCH_SCREEN	CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define	IS_47_INCH_SCREEN	CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define	IS_55_INCH_SCREEN	CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)

// 以5.5寸屏的宽度为基准，计算宽比
#define	SCREEN_WIDTH_RATIO55	KScreenWidth/414.0f
// 以3.5/4寸屏的宽度为基准，计算宽比
 #define	SCREEN_WIDTH_RATIO40	KScreenWidth/320.0f

// 间距 - l=5.5寸flash文件中间距/3.0f
#define	LENGTH_ADAPTED(l)	l * SCREEN_WIDTH_RATIO55
// 4inch的间距
#define LENGTH_4INCH_ADAPTED(l) l

#define LENGTH_SCALE_4INCH_ADAPTED(l) LENGTH_ADAPTED(l/0.77294686f)


// *********************************** 配置信息 ***********************************
/*-------------------- 版本号 --------------------*/
// APP版本的判断
#define KClientVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
// bunld版本号
#define KBUILD_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]
#define Application_Server_Language NSLocalizedString(@"TKN_SERVER_LANGUAGE_ID", @"")
#define Landing_Processing NSLocalizedString(@"TKN_LANDING_PROCESSING", @"NO_Contacts")
#define Landing_Processing2 NSLocalizedString(@"TKN_LANDING_PROCESSING2", @"NO_Contacts")
#define Landing_Hint NSLocalizedString(@"TKN_LANDING_HINT", @"NO_Contacts")

#define KUserAgent @"iPhone/%@.%@ /IOSVersion:%f /Platform:%@"
#define PublishTime [[[NSBundle mainBundle] infoDictionary] objectForKey:@"PublishTime"]
#define IosVersion floorf([[[UIDevice currentDevice] systemVersion] floatValue])

#define appDelegate ((AppDelegate*)[UIApplication sharedApplication].delegate)
#define AlertTitle [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]
#define AppName [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString *)kCFBundleNameKey]
#define appActive ([[UIApplication sharedApplication] applicationState] == UIApplicationStateActive)

// 获取storybord
#define MAIN_STORY_BOARD(Name)                      [UIStoryboard storyboardWithName:Name bundle:nil]

// 通知中心
#define NS_NOTIFICATION_CENTER                      [NSNotificationCenter defaultCenter]

//获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])


// *********************************** UI标准元素 ***********************************
// 开关背景颜色
#define UISwitchBackgroundColor Color(41 ,43,50)
// 开关的剪切半径
#define UISwitchRadius 15

#define UISwithOffColor ColorI(0x596064)
// 提示音开关颜色
#define UISwitchColor  ColorI(0x2cbcd6)
// 背景蒙版颜色
#define MaskBgColor [UIColor colorWithRed:0 green:0 blue:0 alpha:0.8]
// tableview的字体大小
#define tabelViewCellTextFontSize 16
#define tabelViewCellTextColor1 ColorI(0x797979)
// 头像圆圈颜色
#define rankListHeaderColor ColorI(0x7b8391).CGColor
// 头像图片名称
#define HeaderImage [NSString stringWithFormat:@"%.0f.png",[[NSDate date] timeIntervalSince1970] * 1000]

// cell textColor
#define tebleViewCellTextColor ColorI(0xd9d9d9)
// cell 背景颜色
#define tableViewCellBgColor ColorI(0x2b2f37)
// 个人信息页页面的背景颜色
#define tableViewBgColor ColorI(0x023272e)
// 右侧按钮的可按状态的颜色
#define rightBtnColorEnabled ColorA(113, 189, 215, 0.4)
// 右侧按钮的不可按状态的颜色
#define rightBtnColorDisabled ColorI(0x767678)
// 右侧按钮的颜色
#define rightBtnColor ColorA(113, 189, 215, 1.0)

#define comminColor ColorI(0xf6f6f6)

#define KbackgroundColor ColorI(0xe4e4e4)

#define KheaderColor MAIN_FONT_COLOR


// 常用color
#define KClearColor [UIColor clearColor]
#define KWhiteColor [UIColor whiteColor]
#define KBlackColor [UIColor blackColor]
#define KGrayColor [UIColor grayColor]
#define KGray2Color [UIColor lightGrayColor]
#define KBlueColor [UIColor blueColor]
#define KRedColor [UIColor redColor]

#define KMainViewBackgroundColor ColorI(0xf6f6f6)
#define KSubViewBackgroundColor	ColorI(0xffffff)
#define KDescTextColor ColorI(0x7c7c7c)
#define KCommonContentColor ColorI(0x646464)
#define KBlueContentColor ColorI(0x3095ef)

#pragma  
#define KUrlTxtColor Color(18,168,221)
#define kbgcolor ColorI(0x686d73)

// 页面中分割线高度
#define DIVIDE_LINE_HEIGHT	0.5f
#define DIVIDE_LINE_COLOR ColorI(0xdfe1e3)
#define RED_POINT_COLOR ColorI(0xff1f1a)

#define SessionInfo [KSessionInfo sharedSessionInfo]
#define USER_ID [KSessionInfo sharedSessionInfo].uid
#define USER_SESSION [KSessionInfo sharedSessionInfo].sid

// 系统控件默认高度
#define kStatusBarHeight (20.f)
#define kTopBarHeight (44.f)
#define kBottomBarHeight (49.f)
#define kCellDefaultHeight (44.f)
#define kEnglishKeyboardHeight (216.f)
#define kChineseKeyboardHeight (252.f)

// *********************************** 调试信息 ***********************************
#define LOG     NSLog
#define LOGA(f) NSLog(@"%@",f)
#define LOGS(f) NSLog(@"%s",f)
#define LOGN(f) NSLog(@"%d",f)
#define LOGF(f) NSLog(@"%f",f)
#define LogClass NSLog(@"in -- class: %@",self.class)
#define LOGFUN NSLog(@"%s | %d",__FUNCTION__,__LINE__)
#define LOGFUN3 NSLog(@"%s | %d | %s",__FILE__,__LINE__,__FUNCTION__)
#define LogRect2(rect) NSLog(@"rect x:%f y:%f w:%f h:%f",rect.origin.x,rect.origin.y,rect.size.width,rect.size.height)
#define LogSign NSLog(@"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
#define LogRect(rect) NSLog(@"%@",NSStringFromCGRect(rect))
#define LogPt(pt) NSLog(@"%@",NSStringFromCGPoint(pt))
#define LogSize(size) NSLog(@"%@",NSStringFromCGSize(size))

#define WhereLog(value) NSLog(@"function: %s, file: %s, line: %d, msg: %@", __PRETTY_FUNCTION__, __FILE__, __LINE__, value)
#define WhereLog0() NSLog(@"[%@ %@]", [self class], NSStringFromSelector(_cmd))
#define WLOG(str) [GLogger writeLog:[NSString stringWithFormat:@"\r\n%s | %d | %s \r\n%@",__FILE__,__LINE__,__FUNCTION__,str]]

#define DEL(f) { if(f!=nil) [f release]; f=nil; }

// -------------------------------- from weview project
#ifndef __FAIL

// We use usleep() to make sure NSLog buffers are flushed.
// Is there a better way to do this?
#define __FAIL(msg, args...) { \
NSLog(msg, ## args); \
WhereLog(@"failed."); \
__TRIGGER_DEBUGGER(); \
usleep(1000 * 1000); \
exit(-1); \
}

#endif

#ifndef __NOT_IMPLEMENTED
#define __NOT_IMPLEMENTED() [self doesNotRecognizeSelector:_cmd];
#endif

#ifndef deallocProperty
// Use temp local to isolate dealloc loops.
#define deallocProperty(value) { \
if(value != nil) { \
id temp = value; \
value = nil; \
[temp release]; \
} \
}
#endif

#ifndef deallocPtr
#define deallocPtr(ptr) { \
if(ptr != NULL) { \
void* _temp = ptr; \
ptr = NULL; \
free(_temp); \
} \
}
#endif

#ifndef safeMalloc
#define safeMalloc(ptr, size) { ptr = malloc(size); if(ptr == NULL) { __FAIL(@"%@ could not be allocated", @"ptr"); } }
#endif

#ifndef safeCalloc
#define safeCalloc(ptr, size1, size2) { ptr = calloc(size1, size2); if(ptr == NULL) { __FAIL(@"%@ could not be allocated", @"ptr"); } }
#endif
// --------------------------------

#define KCanCamera [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]
#define FileExsit(name) [[NSFileManager defaultManager] fileExistsAtPath:name]
#define Alert2(f) [Utilities Alert2:(f)]
#define Alert3(f) [Utilities Alert3:(f)]
#define Alert(f) [Utilities alert:(f)]
#define AlertBar(msg) [appDelegate asynchronousOperationStatusBar:1 changeLabel:msg]
#define AlertBar2(msg) [appDelegate asynchronousOperationStatusBar:0 changeLabel:msg]
#define AlertNetError Alert(LTXT(TKN_CONNECTTIMEOUT))

#define LTXT(s) NSLocalizedString(@"" #s "",@"")
#define IMG0(s) [appDelegate getDefaultImage:s]
#define IMG(s) [UIImage imageNamed:@"" #s ".png"]
#define IMG2(s) [UIImage imageNamed:s]
// 自动适配图片
#define IMGAuto(s) [UIImage imageAutomaticName:@"" #s ".png"]

// 同高度不同宽度（for iphone6)
#define IMGW(s)	KScreenWidth == 375 ? [UIImage imageNamed:@"" #s "-375.png"] : [UIImage imageNamed:@"" #s ".png"]

// 判断是否为空
#define Str(s) (s==nil || [s isEqualToString:@"(null)"] ? @"" : s)
#define StrDate(s) (s==nil ? [NSDate date] : s)
#define StrNull(f) (f==nil || ![f isKindOfClass:[NSString class]] || ([f isKindOfClass:[NSString class]] && [f isEqualToString:@""]))
#define StrValid(f) (f!=nil && [f isKindOfClass:[NSString class]] && ![f isEqualToString:@""])
#define SafeStr(f) (StrValid(f) ? f:@"")
#define HasString(str,eky) ([str rangeOfString:key].location!=NSNotFound)

#define ValidStr(f) StrValid(f)
#define ValidDict(f) (f!=nil && [f isKindOfClass:[NSDictionary class]] && [f count]>0)
#define ValidArray(f) (f!=nil && [f isKindOfClass:[NSArray class]] && [f count]>0)
#define ValidNum(f) (f!=nil && [f isKindOfClass:[NSNumber class]])
#define ValidClass(f,cls) (f!=nil && [f isKindOfClass:[cls class]])
#define ValidData(f) (f!=nil && [f isKindOfClass:[NSData class]])

#define DataStr(str) [str dataUsingEncoding:NSUTF8StringEncoding]
#define StrData(data) [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease]

#define SF(f) [NSString stringWithFormat:@"%@",f]
#define SFI(f) [NSString stringWithFormat:@"%d",f]
#define SFF(f) [NSString stringWithFormat:@"%f",f]
#define Replace(s,a,b) [s stringByReplacingOccurrencesOfString:a withString:b]

#define Data(s) [data objectForKey:@"" #s ""]
#define DataI(s) [[data objectForKey:@"" #s ""] intValue]
#define DataB(s) [[data objectForKey:@"" #s ""] boolValue]
#define DataS(s) [NSString stringWithFormat:@"%@", [data objectForKey:@"" #s ""]]

#define Dict(s) [dict objectForKey:@"" #s ""]
#define DictI(s) [[dict objectForKey:@"" #s ""] intValue]
#define DictB(s) [[dict objectForKey:@"" #s ""] boolValue]
#define DictS(s) [NSString stringWithFormat:@"%@", [dict objectForKey:@"" #s ""]]

#define UrlEncode(s) (__bridge NSString*)CFURLCreateStringByAddingPercentEscapes(NULL,(CFStringRef)s,NULL,(CFStringRef)@"!*'();:@&=+$,/?%#[]",kCFStringEncodingUTF8)
//NSString decode: [str stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
#define UrlDecode(s) [(NSString*)CFURLCreateStringByReplacingPercentEscapes(NULL,(CFStringRef)s,CFSTR("")) autorelease]
#define UrlDecode2(s) [[[[[s \
stringByReplacingOccurrencesOfString:@"&amp;" withString:@"&"] \
stringByReplacingOccurrencesOfString:@"&gt;" withString:@">"] \
stringByReplacingOccurrencesOfString:@"&lt;" withString:@"<"] \
stringByReplacingOccurrencesOfString:@"&quot;" withString:@"\""] \
stringByReplacingOccurrencesOfString:@"&apos;" withString:@"|'"]
#define UrlDecode3(s) [[[[[[(NSString*)CFURLCreateStringByReplacingPercentEscapes(NULL,(CFStringRef)s,CFSTR("")) autorelease] \
stringByReplacingOccurrencesOfString:@"&amp;" withString:@"&"] \
stringByReplacingOccurrencesOfString:@"&gt;" withString:@">"] \
stringByReplacingOccurrencesOfString:@"&lt;" withString:@"<"] \
stringByReplacingOccurrencesOfString:@"&quot;" withString:@"\""] \
stringByReplacingOccurrencesOfString:@"&apos;" withString:@"|'"]

#define KOldNavBarHeight LENGTH_ADAPTED(56.925f)
#define KNavBarHeight (IosVersion >= 7.0f ? 64.0f : LENGTH_4INCH_ADAPTED(44.0f))
#define KTabBarHeight 49.0f
#define KGPBottomHeight 80

#define	SIDEVIEW_BOUNCE_OFFSET	LENGTH_4INCH_ADAPTED(40.0f)

#if TARGET_IPHONE_SIMULATOR
#define CHECKGPS GPSDONE
#else
#define CHECKGPS [SessionInfo sharedSessionInfo].gpsStatus
#endif

#define ValidLat (USER_LAT!=nil && ![USER_LAT isEqualToString:@""] && [USER_LAT floatValue]!=0)

#define KTableFootHeight 50
#define KTableFootMoreY 8
#define KTableFootIndicatorY 12
#define KTableFootTipY 13


#pragma mark - for ver: 3.2.x
// ------------------------------------------------  color
#define KG_TxtColor_Black Color(0,0,0)
#define KG_TxtColor_DeepGray Color(51,51,51)
#define KG_TxtColor_LightGray Color(40,40,40)
#define KG_TxtColor_Red Color(240,0,0)
#define KG_TxtColor_Yellow Color(255,180,0)
#define KG_WeiboTxt_Color Color(102,102,102)
#define KG_TxtColor_Weibos Color(82,82,82)
#define KG_TxtColor_WeiboTime Color(82,82,82)

#define KG_BtnTxtColor_White Color(255,255,255)
#define KG_BtnTxtColor_White_s Color(140,0,0)
#define KG_BtnTxtColor_Gray Color(153,153,153)
#define KG_BtnTxtColor_Gray_s Color(85,85,85)
#define KG_Time_Color Color(73,73,73)
#define KG_Account_Color Color(187,187,187)

#define KG_LineCheckinResult Color(228,29,0)
#define KG_BottomTxtColor_Gray Color(163,163,163)

#define KG_TxtExploreTitleColor_Blue Color(34,170,238)

// ------------------------------------------------  font
#define KG_NavBarFont FontBold(14)
#define KG_TabControllerBarFont FontBold(10)

#define KG_CheckinBtnFont FontBold(20)
#define KG_BigBtnFont FontBold(15)

#define KG_BigTipFont Font(14)
#define KG_NormalTipFont Font(13)

#define KG_TitleFont Font(15)
#define KG_TitleDesFont Font(14)

#define KG_CellTitleFont Font(15)
#define KG_CellEventTitleFont FontBold(15)
#define KG_CellEventFont Font(14)
#define KG_CellInnerDesFont Font(13)
#define KG_CellDesFont Font(13)
#define KG_CellTimeFont Font(11)
#define KG_CellCommentFont FontBold(11)

// ------------------------------------------------  offset
#define KImageUploadLen 616

#define KJpgQuality 0.3

#define KStatusHeight (IosVersion>=7.0?LENGTH_4INCH_ADAPTED(20):0.0)
#define KNavRightBtnRect CGRectMake(KScreenWidth - 50, 0, 50, 44)
#define KNavRightBtnRect2 CGRectMake(260, KStatusHeight+3.5, 51, 31)
#define KStatusBarHeight (IOS7 ? 0.0f : LENGTH_4INCH_ADAPTED(20))

#define kDocumentsDirectory [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject]


#pragma mark 有空再整合
//BaseViewController
#define FONT_DEFAULT	@"ArialMT"
#define FONT_BOLD_DEFAULT	@"Arial-BoldMT"
#define NUM_MAIN_FONT @"DINAlternate-Bold"
#define FONT_NUM_DEFAULT	@"HelveticaNeue-Light"

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define MAIN_GRAYCOLOR     ColorI(0xf0efeb)
#define MAIN_FONT_COLOR		ColorI(0xf75b4c)

/*---------------------BUTTON_COLOR--------------------*/
#define BUTTON_BG_COLOR_NORMAL	ColorI(0x3095ef)
#define BUTTON_BG_COLOR_SELECTED	ColorI(0x0c64b3)
#define BUTTON_BG_COLOR_DISABLED	ColorI(0x999999)

#define PICK_VIEW_COLOR ColorI(0xefeff4)
#define PICK_Line_COLOR ColorI(0xc4c3bf)

#define TextRedColor ColorI(0xed494a)

#define FONT_DARK_SHADOW_COLOR [UIColor colorWithRed:0x6f/255.0f green:0x77/255.0f blue:0x7c/255.0f alpha:1]
#define FONT_LIGHT_SHADOW_COLOR [UIColor colorWithRed:0xff/255.0f green:0xff/255.0f blue:0xff/255.0f alpha:1];
#define FONT_DARKGRAYCOLOR     [UIColor colorWithRed:0x67/255.0f green:0x6e/255.0f blue:0x73/255.0f alpha:1]
#define CYCLE_GREENCOLOR        [UIColor colorWithRed:0x7c/255.0f green:0xc7/255.0f blue:0x4c/255.0f alpha:1]
#define FONT_GRAYCOLOR [UIColor colorWithRed:0x5e/255.0f green:0x64/255.0f blue:0x6a/255.0f alpha:1]
#define BG_LIGHTGRAYCOLOR   [UIColor colorWithRed:0xea/255.0f green:0xea/255.0f blue:0xea/255.0f alpha:1]
#define CELLBG_LIGHTGRAYCOLOR UIColorFromRGB(0xf8f8f8)
#define CELLFONTCOLOR UIColorFromRGB(0xa6a8ac) 

//ViewController
#define BUTTON_CYCLE_TAG 23
#define CAR_TABEL_TAG 24
#define CYCLEBG_TAG 55
#define MAIN_TABLE_TAG 25
#define BLUETOOTH_BUTTON_TAG 60
#define AIRPLANE_BUTTON_TAG 61
#define LOCALBASE_BUUTON_TAG 62
#define ODB_UNCONNECTED_BUTTON_TAG 63
#define NEWVERSION_BTTON_TAG 64
#define NOTICE_BG 65
#define CAR_BUTTON_TAG 66

#define BUTTON_WIDTH 120
#define BUTTON_HEIGHT 40

#define IMAGE_CAP_INSET_TOP 30.0
#define IMAGE_CAP_INSET_LEFT 30.0
#define IMAGE_CAP_INSET_BOTTOM 30.0
#define IMAGE_CAP_INSET_RIGHT 30.0

#define NORMAL_TOPNODE_FRAME      CGRectMake(57.0, 12, 10, 10)
#define HEIGHTED_TOPNODE_FRAME    CGRectMake(57.0, 0, 11, 45)

// #define MAPHEIGTHBIG 180
#define	MAPHEIGTHBIG	LENGTH_ADAPTED(232.875f)
#define MAPHEIGTSMALL 0

#define kNavBeginTag 108361
#define kMapbtnBeginTag 109371

#define kMapSliderTag 111111
#define kMapbtnMyLocTag 111112
//HACMacro.h
#define RSSI_THRESHOLD -60
#define WARNING_MESSAGE @"z"

#define MAX_PAUSE_TIME_INTERVAL 120
#define MIN_SPECIAL_INTERVAL 5  //认定特殊状态结束的所需的最小时间 单位s

/*--------------------------BASE_URL-----------------------------*/

#if (defined DEBUG) && !(defined IS_RELEASE_URL)
#define BASE_URL @"测试环境BASEURL"
#else
#define BASE_URL @"正式环境BASEURL"
#endif



#ifndef DEBUGLOG
#if DEBUG
//# define DEBUGLOG(fmt, ...) NSLog((@"XBQ: %s [Line %d] \n" fmt),__PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
# define DEBUGLOG(fmt, ...) NSLog((fmt), ##__VA_ARGS__);
#else
#define DEBUGLOG(fmt, ...)
#endif
#endif

// 自定义log
#ifndef NSLog
#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...)
#endif
#endif


#define NSDetailLog(format, ...) \
do { \
NSLog(@"<%@ : %d : %s>-: %@", \
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], \
__LINE__, \
__FUNCTION__, \
[NSString stringWithFormat:format, ##__VA_ARGS__]); \
} while(0)


//判断是否要Log
#ifdef NEED_DEBUG
#define NSDetailLog(format, ...) \
//Log定义...
#else
#define NSDetailLog(format, ...) do{ } while(0)
#endif



#pragma mark - degrees/radian functions
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

#define kcarcolors @{ColorI(0xbbc8d0):@"银色",ColorI(0x596064):@"灰色",ColorI(0x2f3336):@"黑色",ColorI(0xd5c9a6):@"香槟色",ColorI(0xf8f8f8):@"白色",ColorI(0xfecc2f):@"黄色",ColorI(0xfc3b2f):@"红色",ColorI(0xa16b3f):@"棕色",ColorI(0x70ce3f):@"绿色",ColorI(0x4ab4f0):@"蓝色"}
#define kalertviewtag 526170

// *************************** 其他方法 ********************************

#define NumToString(n) [NSString stringWithFormat:@"%@",n]

//app主窗口
#define SCKeyWindow [UIApplication sharedApplication].keyWindow

// 状态条高度
#define SCStatusBarHeight [UIApplication sharedApplication].statusBarFrame.size.height

// G－C－D
// 在Main线程上运行
#define DISPATCH_ON_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
// 在Global Queue上运行
#define DISPATCH_ON_GLOBAL_QUEUE_HIGH(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_DEFAULT(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_LOW(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), globalQueueBlocl);
#define DISPATCH_ON_GLOBAL_QUEUE_BACKGROUND(globalQueueBlocl) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), globalQueueBlocl);

// 由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)

// 加载xib
#define LoadNib(x) [[NSBundle mainBundle] loadNibNamed:@(x) owner:nil options:nil][0]

// 在宏的参数前加上一个#，宏的参数会自动转换成c语言的字符串
#define MRKeyPath(objc,keyPath) @(((void)objc.keyPath, #keyPath))


//** 获得当前的 年 月 日 时 分 秒 *****************************************************************************
#define CurrentSec [[NSCalendar currentCalendar] component:NSCalendarUnitSecond fromDate:[NSDate date]]
#define CurrentMin [[NSCalendar currentCalendar] component:NSCalendarUnitMinute fromDate:[NSDate date]]
#define CurrentHour [[NSCalendar currentCalendar] component:NSCalendarUnitHour fromDate:[NSDate date]]
#define CurrentDay [[NSCalendar currentCalendar] component:NSCalendarUnitDay fromDate:[NSDate date]]
#define CurrentMonth [[NSCalendar currentCalendar] component:NSCalendarUnitMonth fromDate:[NSDate date]]
#define CurrentYear [[NSCalendar currentCalendar] component:NSCalendarUnitYear fromDate:[NSDate date]]


// View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// UIView - viewWithTag
#define VIEWWITHTAG(_OBJECT, _TAG) [_OBJECT viewWithTag : _TAG]

// 本地化字符串
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define LocalString(x, ...) NSLocalizedString(x, nil)
/** NSLocalizedStringFromTable宏做的其实就是在当前bundle中查找资源文件名“xxx.strings”(参数:键＋文件名＋注释) */
#define AppLocalString(x, ...) NSLocalizedStringFromTable(x, @"someName", nil)




