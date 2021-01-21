//
//  MainWindowController.m
//  app
//
//  Created by  zuowu on 2021/1/21.
//

#import "MainWindowController.h"
#import <MetalKit/MetalKit.h>

@interface MainWindowController () <NSWindowDelegate>
{
    NSPoint _mousePoint;
    NSView * _titleLine;
        
    NSButton * _exit;
    NSButton * _min;
    
    NSScrollView * _leftScroll;
    MTKView * _mtkView;
}
@end

@implementation MainWindowController

-(void) loadWindow {
    [super loadWindow];
}

-(void) showWindow:(id)sender {
    [super showWindow:sender];
    //NSLog(@"showWindow");
}

- (void)windowDidLoad {
    
    [super windowDidLoad];
    
    self.window.backgroundColor = [NSColor darkGrayColor];
    self.window.delegate = self;
    _titleLine = [[NSView alloc] init];
    _titleLine.wantsLayer = YES;
    //_titleLine.layer.backgroundColor = [NSColor blueColor].CGColor;
    [self.window.contentView addSubview:_titleLine];
    
    _exit = [[NSButton alloc] init];
    _exit.title = @"e";
    _exit.target = self;
    _exit.action = @selector(onClose:);
    [_titleLine addSubview: _exit];
    
    _min = [[NSButton alloc] init];
    _min.title = @"m";
    _min.target = self;
    _min.action = @selector(onMin:);
    [_titleLine addSubview: _min];
    
    _leftScroll = [[NSScrollView alloc] init];
    _leftScroll.backgroundColor = [NSColor blackColor];
    [self.window.contentView addSubview:_leftScroll];
    
    _mtkView = [[MTKView alloc] init];
    _mtkView.layer.backgroundColor = [NSColor brownColor].CGColor;
    [self.window.contentView addSubview:_mtkView];
    
    [self layout];

}

- (void) layout {
    
    CGSize windowSize = self.window.frame.size;
    
    CGFloat height = 20;
    
    _titleLine.frame = CGRectMake(0, windowSize.height - height, windowSize.width, height);
    
    height = 20;
    _exit.frame = CGRectMake(0, 0, height, height);
    _min.frame = CGRectMake(height, 0, height, height);
    
    CGFloat padding = 10;
    _leftScroll.frame = CGRectMake(padding, padding , 100, windowSize.height - height - padding);
    
    _mtkView.frame = CGRectMake(_leftScroll.frame.origin.x + _leftScroll.frame.size.width + 10,
                                padding,
                                windowSize.width - _leftScroll.frame.origin.x - _leftScroll.frame.size.width - padding*2,
                                windowSize.height - height - padding);
    
}

- (void) onClose: (id) sender {
    [self.window close];
    [[NSApplication sharedApplication] terminate:nil];
}
- (void) onMin: (id) sender {
    [self.window miniaturize:nil];
}




-(void) mouseEntered:(NSEvent *)event{
    //NSLog(@"mouseEntered");
}

-(void) mouseDown:(NSEvent *)event {
    _mousePoint = NSEvent.mouseLocation;
}

-(void) mouseUp:(NSEvent *)event {
    //NSLog(@"mouseUp");
}


- (void) mouseDragged:(NSEvent *)event {
    
    [event locationInWindow];
    
    NSPoint point = NSEvent.mouseLocation;
    
    CGFloat dx = point.x - _mousePoint.x;
    CGFloat dy = point.y - _mousePoint.y;
    //NSLog(@"dx = %f, dy = %f", dx, dy);
    
    CGPoint pos = self.window.frame.origin;
    
    CGRect frame = {{pos.x+dx, pos.y+dy}, self.window.frame.size};
    [self.window setFrame: frame display:YES];
    
    _mousePoint = point;
    
}

- (NSSize)windowWillResize:(NSWindow *)sender toSize:(NSSize)frameSize {
    //NSLog(@"windowWillResize");
    return frameSize;
}

- (void) windowDidResize:(NSNotification *)notification {
    //NSLog(@"windowDidResize");
    [self layout];
}

- (void) windowDidMove:(NSNotification *)notification {
    [self layout];
}

@end
