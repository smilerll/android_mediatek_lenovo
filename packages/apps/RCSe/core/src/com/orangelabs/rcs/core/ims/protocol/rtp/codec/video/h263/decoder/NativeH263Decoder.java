/*******************************************************************************
 * Software Name : RCS IMS Stack
 *
 * Copyright (C) 2010 France Telecom S.A.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

package com.orangelabs.rcs.core.ims.protocol.rtp.codec.video.h263.decoder;


// Referenced classes of package com.orangelabs.rcs.core.ims.protocol.rtp.codec.video.h263.decoder:
//            VideoSample

public class NativeH263Decoder
{

    public NativeH263Decoder()
    {
    }

    public static native int InitDecoder(int i, int j);

    public static native int DeinitDecoder();

    public static native int DecodeAndConvert(byte abyte0[], int ai[], long l);

    public static native int InitParser(String s);

    public static native int DeinitParser();

    public static native int getVideoLength();

    public static native int getVideoWidth();

    public static native int getVideoHeight();

    public static native String getVideoCoding();

    public static native VideoSample getVideoSample(int ai[]);

    /**
     * M: Added for video share progress control @{
     */
    public static native int seekTo(long timestamp);

    /** @}*/
    static 
    {
        String libname = "H263Decoder";
        try
        {
            System.loadLibrary(libname);
        }
        catch(Exception exception) { }
    }
}
