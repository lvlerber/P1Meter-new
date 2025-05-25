#pragma once

#include "Arduino.h"
#include "ArduinoNvs.h"
typedef enum{

// Admin,
 CONFIG_ADMIN_AUTH,
 CONFIG_ADMIN_USERNAME,
 CONFIG_ADMIN_PASSWORD,

// MQTT,

 CONFIG_MQTT_HOST,
 CONFIG_MQTT_PORT,
 CONFIG_MQTT_ROOT_TOPIC,
 CONFIG_MQTT_USERNAME,
 CONFIG_MQTT_PASSWORD,
 
// P1Meter

 CONFIG_P1_UPD_INT,
 CONFIG_P1_FULL_UPD_INT,

// WiFi,
 CONFIG_WIFI_AP_ACTIVE,
 CONFIG_WIFI_AP_COLOR,
 CONFIG_WIFI_AP_SSID,
 CONFIG_WIFI_AP_SSID_HIDDEN,
 CONFIG_WIFI_AP_AUTH_MODE,
 CONFIG_WIFI_AP_PASSWORD,
 CONFIG_WIFI_AP_GATEWAY,
 CONFIG_WIFI_AP_SUBNET,

 CONFIG_WIFI_STA_ACTIVE,
 CONFIG_WIFI_STA_COLOR,
 CONFIG_WIFI_STA_SSID,
 CONFIG_WIFI_STA_PASSWORD,
 CONFIG_WIFI_STA_SSID_2,
 CONFIG_WIFI_STA_PASSWORD_2,
 CONFIG_WIFI_STA_SSID_3,
 CONFIG_WIFI_STA_PASSWORD_3,
 CONFIG_WIFI_STA_SCAN_MODE_ALL,
 CONFIG_WIFI_STA_STATIC,
 CONFIG_WIFI_STA_IP,
 CONFIG_WIFI_STA_GATEWAY,
 CONFIG_WIFI_STA_SUBNET,
 CONFIG_WIFI_STA_DNS_A,
 CONFIG_WIFI_STA_DNS_B,
 // size of the config item array
 CONFIG_ITEM_SIZE
} config_item_t;
typedef enum {
    CONFIG_ITEM_TYPE_BOOL = 0,
    CONFIG_ITEM_TYPE_INT8,
    CONFIG_ITEM_TYPE_INT16,
    CONFIG_ITEM_TYPE_INT32,
    CONFIG_ITEM_TYPE_INT64,
    CONFIG_ITEM_TYPE_UINT8,
    CONFIG_ITEM_TYPE_UINT16,
    CONFIG_ITEM_TYPE_UINT32,
    CONFIG_ITEM_TYPE_UINT64,
    CONFIG_ITEM_TYPE_STRING,
    CONFIG_ITEM_TYPE_BLOB,
    CONFIG_ITEM_TYPE_COLOR,
    CONFIG_ITEM_TYPE_IP,
    CONFIG_ITEM_TYPE_MAX
} config_item_type_t;

union config_color_t {
    struct values {
        uint8_t alpha;
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    } values;
    uint32_t rgba;
} ;

union config_ip_addr_t{
    uint8_t bytes[4];  // IPv4 address
    uint32_t addr;
    config_ip_addr_t( int byte1, int byte2, int byte3, int byte4 ) :
        bytes{(uint8_t) byte1,(uint8_t) byte2,(uint8_t) byte3,(uint8_t) byte4} {}
} ;

class ConfNvs {
    public:
        void begin();
};


class ConfigItem {
    public:
        String key;
        config_item_type_t type;
        bool secret;
 
    ConfigItem(std::string  key , config_item_type_t type, bool secret) ;    

    ConfigItem(const char  *key, config_item_type_t type, bool secret ) ;
    ConfigItem();
    ConfigItem(const ConfigItem &x) ;
    void saveValueFromString(const String value);
} ;

extern ConfigItem CONFIG_ITEMS[];
