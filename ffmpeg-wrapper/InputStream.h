//
//  InputStream.h
//  ffmpeg-wrapper
//
//  Created by Min Kim on 10/7/13.
//  Copyright (c) 2013 iFactory Lab Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libavformat/avformat.h"

@interface InputStream : NSObject

@property (atomic, assign) AVCodec *codec;
@property (atomic, assign) AVStream *stream;
@property (atomic, assign) NSUInteger fileIndex;
@property (atomic, assign) NSInteger resampleHeight;
@property (atomic, assign) NSInteger resampleWidth;
@property (atomic, assign) NSInteger resamplePixFmt;
@property (atomic, assign) NSInteger guessLayoutMax;
@property (atomic, assign) NSInteger resampleSampleFmt;
@property (atomic, assign) NSInteger resampleSampleRate;
@property (atomic, assign) NSInteger resampleChannels;
@property (atomic, assign) uint64_t resampleChannelLayout;
@property (atomic, assign) NSInteger discard;
// true if the packets must be decoded in 'raw_fifo'
@property (atomic, assign)  int decodingNeeded;

// video only
@property (atomic, assign) AVRational frameRate;

// is 1 at the start and after a discontinuity
@property (atomic, assign) NSInteger isStart;
@property (atomic, assign) NSInteger wrapCorrectionDone;
@property (atomic, assign) double tsScale;
@property (atomic, assign) NSInteger sawFirstTs;

// synthetic pts for the next decode frame (in AV_TIME_BASE units)
@property (atomic, assign) int64_t nextPts;
// current pts of the decoded frame  (in AV_TIME_BASE units)
@property (atomic, assign) int64_t pts;
@property (atomic, assign) int64_t nextDts;
// dts of the last packet read for this stream (in AV_TIME_BASE units)
@property (atomic, assign) int64_t dts;
@property (atomic, assign) int64_t filterInRescaleDeltaLast;

- (id)initWithStream:(AVStream *)stream;
- (int)guessInputChannelLayout;

@end
