//
//     Generated by classdumpios 1.0.1 (64 bit) (iOS port by DreamDevLost)(Debug version compiled Sep 26 2020 00:23:19).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import "NSObject-Protocol.h"

@class UISearchController;
@protocol UISearchSuggestion;

@protocol UISearchResultsUpdating <NSObject>
- (void)updateSearchResultsForSearchController:(UISearchController *)arg1;

@optional
- (void)updateSearchResultsForSearchController:(UISearchController *)arg1 selectingSearchSuggestion:(id <UISearchSuggestion>)arg2;
@end

