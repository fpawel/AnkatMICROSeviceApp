#ifndef MY_MENU_ITEMS_HELPER_INCLUDED___
#define MY_MENU_ITEMS_HELPER_INCLUDED___

#include <Menus.hpp>
#include "loki\Functor.h"
namespace MyPm
{

	struct SetOnClickFn
	{
		const TNotifyEvent onClick_;
		explicit SetOnClickFn(TNotifyEvent onClick) : onClick_( onClick ) {}
		void operator()(TMenuItem* itm) { itm->OnClick = onClick_; }
	};
	struct SetVisibilityFn
	{
		const bool vis_;
		explicit SetVisibilityFn(bool vis) : vis_( vis ) {}
		void operator()(TMenuItem* itm) { itm->Visible = vis_; }
	};
	struct SetEnabilityFn
	{
		const bool vis_;
		explicit SetEnabilityFn(bool vis) : vis_( vis ) {}
		void operator()(TMenuItem* itm) { itm->Enabled = vis_; }
	};


	void ForEachPmItem( TPopupMenu* pm, Loki::Functor<void, TYPELIST_1(TMenuItem*) > f )
	{
		size_t i = pm->Items->Count;
		for( ; i; --i )
			f(pm->Items->Items[i-1]);
	}

	// установить единый хендлер Onclick для всех подменю
	void SetPmOnClick( TPopupMenu* pm, TNotifyEvent onClick )
	{
		ForEachPmItem( pm, SetOnClickFn(onClick) );
	}

};


#endif
