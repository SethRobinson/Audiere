#ifndef ADR_WX_STREAM_FRAME_H
#define ADR_WX_STREAM_FRAME_H


#include <audiere.h>
#include "wx.h"


class StreamFrame : public wxMDIChildFrame {
public:
  StreamFrame(
    wxMDIParentFrame* parent,
    const wxString& title,
    audiere::OutputStream* stream,
    audiere::SampleSource* source,
    audiere::LoopPointSource* loop_source = 0);
  ~StreamFrame();

  void OnPlay();
  void OnStop();
  void OnReset();
  void OnEditLoopPoints();
  void OnViewTags();

  void OnRepeat();
  void OnChangeVolume();
  void OnChangePan();
  void OnChangePitch();
  void OnChangePos();
  void OnUpdateStatus();
  void UpdateVPPLabel();
  void UpdateLengthPosLabel();

private:
  audiere::OutputStreamPtr m_stream;
  audiere::SampleSourcePtr m_source;

  /// Only a valid pointer when the output stream is fed from it.
  audiere::LoopPointSourcePtr m_loop_source;

  bool m_stream_is_seekable;
  int m_stream_length;

  wxTimer* m_timer;

  wxStaticText* m_playing_label;
  wxCheckBox*   m_repeating;
  wxStaticText* m_vpp_label;
  wxSlider*     m_volume;
  wxSlider*     m_pan;
  wxSlider*     m_pitch;
  wxStaticText* m_length_pos_label;
  wxSlider*     m_pos;

  DECLARE_EVENT_TABLE()
};


#endif
