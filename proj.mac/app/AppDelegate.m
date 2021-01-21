//
//  AppDelegate.m
//  app
//
//  Created by  zuowu on 2021/1/21.
//

#import "AppDelegate.h"
#import "MainWindowController.h"

@interface AppDelegate ()

@property (nonatomic, strong) MainWindowController * wc;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {

    CGSize screenSize = [NSScreen mainScreen].frame.size;
    CGSize windowSize = CGSizeMake(960, 640);
    CGSize windowMinSize = CGSizeMake(480, 320);
    CGSize windowMaxSize = CGSizeMake(1400, 900);
    CGPoint windowPosition = CGPointMake((screenSize.width-windowSize.width)/2, (screenSize.height-windowSize.height)/2);
    CGRect windowFrame = {windowPosition, windowSize};
    
    NSWindow * window =  [[NSWindow alloc] initWithContentRect: windowFrame
                                                     styleMask: NSWindowStyleMaskMiniaturizable |
                                                                //NSWindowStyleMaskTitled         |
                                                                NSWindowStyleMaskResizable
                                                       backing: NSBackingStoreBuffered
                                                         defer: YES];
    
    [window setMinSize:windowMinSize];
    [window setMaxSize:windowMaxSize];

    _wc = [[MainWindowController alloc] initWithWindow:window];
    [_wc windowDidLoad];
    [_wc showWindow:nil];
        
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
