/* Copyright (C) 2005, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <QSettings>
#include "Settings.h"
#include "Global.h"

Settings::Settings() {
	atTransmit = VAD;
	ptTransmit = PositionVelocity;
	a3dModel = Panning;
	bMute = bDeaf = false;
	bTTS = true;
	iQuality = 8;
	iComplexity = 4;
	iMinLoudness = 4000;
	iVoiceHold = 30;
	iJitterBufferSize = 8;
	iDXOutputDelay = 1;
	fDXMinDistance = 5.0;
	fDXMaxDistance = 35.0;
	fDXDoppler = 0.0;
	fDXRollOff = 0.5;
}

void Settings::load() {
	bMute = g.qs->value("AudioMute", false). toBool();
	bDeaf = g.qs->value("AudioDeaf", false). toBool();
	bTTS = g.qs->value("TextToSpeech", bTTS). toBool();
	atTransmit = static_cast<Settings::AudioTransmit>(g.qs->value("AudioTransmit", Settings::VAD).toInt());
	ptTransmit = static_cast<Settings::PosTransmit>(g.qs->value("PosTransmit", Settings::PositionVelocity).toInt());
	a3dModel = static_cast<Settings::Audio3D>(g.qs->value("Audio3D", Settings::Full).toInt());
	iQuality = g.qs->value("AudioQuality", iQuality).toInt();
	iComplexity = g.qs->value("AudioComplexity", iComplexity).toInt();
	iMinLoudness = g.qs->value("AudioMinLoudness", iMinLoudness).toInt();
	iVoiceHold = g.qs->value("AudioVoiceHold", iVoiceHold).toInt();
	iJitterBufferSize = g.qs->value("JitterBufferSize", iJitterBufferSize).toInt();
	iDXOutputDelay = g.qs->value("DXOutputDelay", iDXOutputDelay).toInt();
	qbaDXInput = g.qs->value("DXInput").toByteArray();
	qbaDXOutput = g.qs->value("DXOutput").toByteArray();
	fDXMinDistance = g.qs->value("DXMinDistance", fDXMinDistance).toDouble();
	fDXMaxDistance = g.qs->value("DXMaxDistance", fDXMaxDistance).toDouble();
	fDXDoppler = g.qs->value("DXDoppler", fDXDoppler).toDouble();
	fDXRollOff = g.qs->value("DXRollOff", fDXRollOff).toDouble();
	qsASIOclass = g.qs->value("ASIOclass").toString();
	qlASIOmic = g.qs->value("ASIOmic").toList();
	qlASIOspeaker = g.qs->value("ASIOspeaker").toList();
}

void Settings::save() {
	g.qs->setValue("AudioMute", g.s.bMute);
	g.qs->setValue("AudioDeaf", g.s.bDeaf);
	g.qs->setValue("TextToSpeech", g.s.bTTS);
	g.qs->setValue("PosTransmit", g.s.ptTransmit);
	g.qs->setValue("AudioTransmit", g.s.atTransmit);
	g.qs->setValue("Audio3D", g.s.a3dModel);
	g.qs->setValue("AudioQuality", iQuality);
	g.qs->setValue("AudioComplexity", iComplexity);
	g.qs->setValue("AudioMinLoudness", iMinLoudness);
	g.qs->setValue("AudioVoiceHold", iVoiceHold);
	g.qs->setValue("JitterBufferSize", iJitterBufferSize);
	g.qs->setValue("DXOutputDelay", iDXOutputDelay);
	g.qs->setValue("DXInput", qbaDXInput);
	g.qs->setValue("DXOutput", qbaDXOutput);
	g.qs->setValue("DXMinDistance", fDXMinDistance);
	g.qs->setValue("DXMaxDistance", fDXMaxDistance);
	g.qs->setValue("DXDoppler", fDXDoppler);
	g.qs->setValue("DXRollOff", fDXRollOff);
	g.qs->setValue("ASIOclass", qsASIOclass);
	g.qs->setValue("ASIOmic", qlASIOmic);
	g.qs->setValue("ASIOspeaker", qlASIOspeaker);
}
