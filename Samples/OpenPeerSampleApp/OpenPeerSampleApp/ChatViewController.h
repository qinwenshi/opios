/*
 
 Copyright (c) 2013, SMB Phone Inc.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#import <UIKit/UIKit.h>

@class Message;
@class Session;
@interface ChatViewController : UIViewController <UITextViewDelegate,UIActionSheetDelegate,UITableViewDelegate, UITableViewDataSource>
{
    IBOutlet UIView *typingMessageView;
    IBOutlet UIButton *sendButton;
    
    BOOL _defaultsSet;
    BOOL _isChatAndVideoActivated;
    BOOL _keyboardIsHidden;
    
    // chat
    IBOutlet UITableView *chatTableView;
    IBOutlet UITextView *messageTextbox;
    
    float _chatHeight;
    float _headerHeight;
    float _keyboardLastChange;
    float _portraitMaxHeight;
    float _landscapeMaxHeight;
    float _portraitFullScreenHeight;
    float _landscapeFullScreeHeight;
    bool _removeKeyboardAndDeactivateChat;
}

@property(nonatomic,assign) Session* session;
//@property(nonatomic,assign) NSMutableArray *arrayMessages;
//@property(nonatomic,assign) BOOL keyboardIsHidden;
@property(nonatomic,assign) BOOL shouldCloseSession;


- (id)initWithSession:(Session*)inSession;

- (void)refreshViewWithData;
- (void)setFramesSizes;
- (float)getHeaderHeight:(float)tableViewHeight;

- (float)getHeaderHeight:(float)tableViewHeight;

- (void)setMessage:(Message *)message;
- (void) updateSessionView;

- (void)registerForNotifications:(BOOL)registerForNotifications;


- (IBAction) closeSession:(id) sender;

//- (void)sendIMmessage:(NSString *)message toRecipient:(id)recipient forMessageEvent:(MessageEvent)messageEvent andImage:(UIImage*)img;
- (void)sendIMmessage:(NSString *)message;
//- (void)sendIMmessage:(NSString *)message forMessageEvent:(MessageEvent)messageEvent andImage:(UIImage*)img;

-(void)setDefaults;

- (void) setKeyboardIsHidden:(BOOL) hidden;
-(CGSize)calcMessageHeight:(NSString *)message forScreenWidth:(float)width;

- (IBAction) sendButtonPressed:(id) sender;
- (IBAction) actionBack;
@end
