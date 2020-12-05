#import <UIKit/UIKit.h>


@interface UIView (RecursiveFind)

- (BOOL)darkMode;
- (id) clone;
- (UIImage *)snapshotViewWithSize:(CGSize)size;
- (UIImage *) snapshotView;
- (UIView *)findFirstSubviewWithClass:(Class)theClass;
- (void)printRecursiveDescription;
- (void)removeAllSubviews;
- (void)printAutolayoutTrace;
//- (NSString *)recursiveDescription;
//- (id)_recursiveAutolayoutTraceAtLevel:(long long)arg1;
@end

