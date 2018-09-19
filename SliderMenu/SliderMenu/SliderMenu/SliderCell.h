//
//  AppDelegate.h
//  SliderMenu
//
//  Created by 雎琳 on 2018/9/13.
//  Copyright © 2018年 雎琳. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MenuItem;

@protocol SliderMenuDelegate

/**
 * @return menu 的 items对象
 */
- (NSArray<MenuItem *> *)sliderMenuItemsForIndexPath:(NSIndexPath *)indexPath;

@optional

/**
 *  复用说明
 * menu如果都是统一样式，可设置复用Identifier 。当设置复用时，cell会一直使用第一次创建的menu
 * menu不是同一样式,不设置此方法、或者返回nil;
 * @return 复用identify
 */
- (NSString *)sliderMenuReuseIdentifier;

/**
 * @return 点击后是否自动关闭 ture：关闭 
 */
- (BOOL)sliderMenuDidSelectIndex:(NSInteger)index atIndexPath:(NSIndexPath *)indexPath;


@end

@interface SliderCell : UITableViewCell

@property (weak, nonatomic) NSObject<SliderMenuDelegate> *menuDelegate;

/**
 * @param open 打开 / 关闭
 * @param time 时间
 * @param springX 正数：右摇动； 负数：左摇动 ； 0：不spring 。数值代表幅度
 */
- (void)openMenu:(BOOL)open time:(NSTimeInterval)time springX:(CGFloat)springX;


@end
