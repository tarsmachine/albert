// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "fileindexwidget.h"

/**************************************************************************/
FileIndexWidget::FileIndexWidget(FileIndex *srv, QWidget *parent) :
	QWidget(parent), _ref(srv)
{
	ui.setupUi(this);

	// Set current values
	ui.comboBoxSearchType->setCurrentIndex(static_cast<int>(_ref->searchType()));

	// Rect to changes
	connect(ui.comboBoxSearchType,SIGNAL(activated(int)),this,SLOT(onSearchTypeChanged(int)));

}

/**************************************************************************/
void FileIndexWidget::onSearchTypeChanged(int st)
{
	_ref->setSearchType(static_cast<IndexService::SearchType>(st));
}
