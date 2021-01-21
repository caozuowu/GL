//
//  main.m
//  app
//
//  Created by  zuowu on 2021/1/21.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        AppDelegate * delegate = [[AppDelegate alloc] init];
        NSApplication * app = [NSApplication sharedApplication];
        app.delegate = delegate;
        [app run];
    }
    return 0;
}
