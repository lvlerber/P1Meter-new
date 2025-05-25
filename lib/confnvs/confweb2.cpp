#include "confweb.h"
#include "confnvs.h"
ConfWeb confWeb;
ConfWebParameter cwp[CONFIG_ITEM_SIZE];
#define PASSWORD_REPLACEMENT "**************"
void save_config_callback()
{
    String value="";
    for (int i=0;i<CONFIG_ITEM_SIZE;i++) {
        value=cwp[i].getValue();        
        if ( CONFIG_ITEMS[i].secret && (value==PASSWORD_REPLACEMENT)) {
            // password has not been changed so will not be overwritten
        } else {
            CONFIG_ITEMS[i].saveValueFromString(value);
        }        
    }
}
void runConfigurationWebsite(){
    std::string value="";
    confWeb.setSaveParamsCallback(save_config_callback);
    for (int i=0;i<CONFIG_ITEM_SIZE;i++) {
        if (CONFIG_ITEMS[i].type== CONFIG_ITEM_TYPE_STRING)
        {
            value = NVS.getString(CONFIG_ITEMS[i].key).c_str();
        } else{
            value=std::to_string(NVS.getInt(CONFIG_ITEMS[i].key));
        }
        if (CONFIG_ITEMS[i].secret) {
            value=PASSWORD_REPLACEMENT;
        }
        //ConfWebParameter dummy(CONFIG_ITEMS[i].key.c_str(),CONFIG_ITEMS[i].key.c_str(),value,64);
        cwp[i].init(CONFIG_ITEMS[i].key.c_str(),CONFIG_ITEMS[i].key.c_str(),value.c_str(),64,"",WFM_LABEL_DEFAULT);
        confWeb.addParameter(&cwp[i]);
    }
    Serial1.println("before startwebportal");
    confWeb.startWebPortal();
    while(1) {
        confWeb.process();
        delay(2);
    }
}
