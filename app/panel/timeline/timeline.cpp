/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2022 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "timeline.h"

#include "panel/panelmanager.h"
#include "panel/project/footagemanagementpanel.h"

namespace olive {

TimelinePanel::TimelinePanel(QWidget *parent) :
  TimeBasedPanel(QStringLiteral("TimelinePanel"), parent)
{
  TimelineWidget* tw = new TimelineWidget();
  SetTimeBasedWidget(tw);

  Retranslate();

  connect(tw, &TimelineWidget::BlockSelectionChanged, this, &TimelinePanel::BlockSelectionChanged);
  connect(tw, &TimelineWidget::RequestCaptureStart, this, &TimelinePanel::RequestCaptureStart);
  connect(tw, &TimelineWidget::RevealViewerInProject, this, &TimelinePanel::RevealViewerInProject);
  connect(tw, &TimelineWidget::RevealViewerInFootageViewer, this, &TimelinePanel::RevealViewerInFootageViewer);
}

void TimelinePanel::SplitAtPlayhead()
{
  timeline_widget()->SplitAtPlayhead();
}

void TimelinePanel::LoadData(const Info &info)
{
  timeline_widget()->RestoreSplitterState(QByteArray::fromBase64(info.at("splitter").toUtf8()));
}

PanelWidget::Info TimelinePanel::SaveData() const
{
  Info i;

  i["splitter"] = timeline_widget()->SaveSplitterState().toBase64();

  return i;
}

void TimelinePanel::SelectAll()
{
  timeline_widget()->SelectAll();
}

void TimelinePanel::DeselectAll()
{
  timeline_widget()->DeselectAll();
}

void TimelinePanel::RippleToIn()
{
  timeline_widget()->RippleToIn();
}

void TimelinePanel::RippleToOut()
{
  timeline_widget()->RippleToOut();
}

void TimelinePanel::EditToIn()
{
  timeline_widget()->EditToIn();
}

void TimelinePanel::EditToOut()
{
  timeline_widget()->EditToOut();
}

void TimelinePanel::DeleteSelected()
{
  timeline_widget()->DeleteSelected(false);
}

void TimelinePanel::RippleDelete()
{
  timeline_widget()->DeleteSelected(true);
}

void TimelinePanel::IncreaseTrackHeight()
{
  timeline_widget()->IncreaseTrackHeight();
}

void TimelinePanel::DecreaseTrackHeight()
{
  timeline_widget()->DecreaseTrackHeight();
}

void TimelinePanel::ToggleLinks()
{
  timeline_widget()->ToggleLinksOnSelected();
}

void TimelinePanel::PasteInsert()
{
  timeline_widget()->PasteInsert();
}

void TimelinePanel::DeleteInToOut()
{
  timeline_widget()->DeleteInToOut(false);
}

void TimelinePanel::RippleDeleteInToOut()
{
  timeline_widget()->DeleteInToOut(true);
}

void TimelinePanel::ToggleSelectedEnabled()
{
  timeline_widget()->ToggleSelectedEnabled();
}

void TimelinePanel::SetColorLabel(int index)
{
  timeline_widget()->SetColorLabel(index);
}

void TimelinePanel::NudgeLeft()
{
  timeline_widget()->NudgeLeft();
}

void TimelinePanel::NudgeRight()
{
  timeline_widget()->NudgeRight();
}

void TimelinePanel::MoveInToPlayhead()
{
  timeline_widget()->MoveInToPlayhead();
}

void TimelinePanel::MoveOutToPlayhead()
{
  timeline_widget()->MoveOutToPlayhead();
}

void TimelinePanel::RenameSelected()
{
  timeline_widget()->RenameSelectedBlocks();
}

void TimelinePanel::InsertFootageAtPlayhead(const QVector<ViewerOutput *> &footage)
{
  timeline_widget()->InsertFootageAtPlayhead(footage);
}

void TimelinePanel::OverwriteFootageAtPlayhead(const QVector<ViewerOutput *> &footage)
{
  timeline_widget()->OverwriteFootageAtPlayhead(footage);
}

void TimelinePanel::Retranslate()
{
  TimeBasedPanel::Retranslate();

  SetTitle(tr("Timeline"));
}

}
