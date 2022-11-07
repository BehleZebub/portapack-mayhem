#include "ui_apt_rx.hpp"
#include "portapack.hpp"
#include <cstring>

using namespace portapack;

namespace ui
{

    void APTRXView::focus()
    {                                // Default selection to button_helloWorld when app starts
	    options_freq.focus();
    }

    APTRXView::APTRXView(NavigationView &nav)                // Application Main
    {
        add_children({                                       // Add pointers for widgets
            &labels_gain,
            &field_lna,
            &field_vga,
            &field_rf_amp,
//            &rssi,
            &labels_freq,
            &options_freq,
            &field_freq
        });

        options_freq.on_change = [this](size_t n, OptionsField::value_t v)
        {
            switch(n)
            {
                case 0: asdf=137620000; break;  // NOAA 15
                case 1: asdf=137912500; break;  // NOAA 18
                case 2: asdf=137100000; break;  // NOAA 19
            }
            field_freq.set_value(asdf);
        };
    }

    void APTRXView::update()                                 // Every time you get a DisplayFrameSync message this
    {                                                        // function will be ran.
         // Message code
    }
}
