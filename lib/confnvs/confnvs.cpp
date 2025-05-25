using namespace std;

#include "confnvs.h"
#include <iostream>

ConfigItem::ConfigItem(const char *key, config_item_type_t type, bool secret)
    : key(key), type(type), secret(secret) {}

ConfigItem::ConfigItem(std::string key, config_item_type_t type, bool secret)
    : key(key.c_str()), type(type), secret(secret) {}

ConfigItem::ConfigItem() : key{std::move("not defined")}, type(CONFIG_ITEM_TYPE_MAX), secret(false) {}

ConfigItem::ConfigItem(const ConfigItem &x)
{
    // std::cout << "before"<<x.key<< " "<<x.type<<" ";
    key = x.key;
    type = x.type;
    secret = x.secret;
}

void ConfigItem::saveValueFromString(const String value)
{
    switch (type)
    {
    case CONFIG_ITEM_TYPE_BOOL:
    {
        bool boolValue = value.toInt();
        NVS.setInt(key, boolValue);
        break;
    }
    case CONFIG_ITEM_TYPE_INT8:
    {
        int8_t int8Value = value.toInt();
        NVS.setInt(key, int8Value);
        break;
    }
    case CONFIG_ITEM_TYPE_INT16:
    {
        int16_t int16Value = value.toInt();
        NVS.setInt(key, int16Value);
        break;
    }
    case CONFIG_ITEM_TYPE_INT32:
    {
        int32_t int32Value = value.toInt();
        NVS.setInt(key, int32Value);
        break;
    }
    case CONFIG_ITEM_TYPE_INT64:
    {
        int64_t int64Value = value.toInt();
        NVS.setInt(key, int64Value);
        break;
    }
    case CONFIG_ITEM_TYPE_UINT8:
    {
        uint8_t int8Value = value.toInt();
        NVS.setInt(key, int8Value);
        break;
    }
    case CONFIG_ITEM_TYPE_UINT16:
    {
        uint16_t int16Value = value.toInt();
        NVS.setInt(key, int16Value);
        break;
    }
    case CONFIG_ITEM_TYPE_UINT32:
    {
        uint32_t int32Value = value.toInt();
        NVS.setInt(key, int32Value);
        break;
    }
    case CONFIG_ITEM_TYPE_UINT64:
    {
        uint64_t int64Value = value.toInt();
        NVS.setInt(key, int64Value);
        break;
    }
    case CONFIG_ITEM_TYPE_STRING:
    {
        NVS.setString(key, value);
        break;
    }
    case CONFIG_ITEM_TYPE_BLOB:
    {
        NVS.setString(key, value);
        break;
    }
    case CONFIG_ITEM_TYPE_COLOR:
    {
        uint32_t int32Value = value.toInt();
        NVS.setInt(key, int32Value);
        break;
    }
    case CONFIG_ITEM_TYPE_IP:
    {
        IPAddress ip;
        ip.fromString(value);
        NVS.setInt(key, uint32_t(ip));
    }
    break;

    default:

        break;
    }
}
ConfigItem CONFIG_ITEMS[CONFIG_ITEM_SIZE];

// Admin
void printci(ConfigItem ci)
{

    std::string typedesc;
    switch (ci.type)
    {
    case CONFIG_ITEM_TYPE_BOOL:
        typedesc = "BOOL";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << NVS.getInt(ci.key) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_INT8:
        typedesc = "INT8";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << std::to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_INT16:
        typedesc = "INT16";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_INT32:
        typedesc = "INT32";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_INT64:
        typedesc = "INT64";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_UINT8:
        typedesc = "UINT8";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_UINT16:
        typedesc = "UINT16";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_UINT32:
        typedesc = "UINT32";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_UINT64:
        typedesc = "UINT64";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string(NVS.getInt(ci.key)) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_STRING:
        typedesc = "STRING";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << NVS.getString(ci.key).c_str() << std::endl;
        break;
    case CONFIG_ITEM_TYPE_BLOB:
        typedesc = "BLOB";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t"
                  << " no blobs please  " << std::endl;
        break;
    case CONFIG_ITEM_TYPE_COLOR:
        typedesc = "COLOR";
        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << NVS.getInt(ci.key) << std::endl;
        break;
    case CONFIG_ITEM_TYPE_IP:
    {
        typedesc = "IP";
        config_ip_addr_t dummyip(0, 0, 0, 0);
        dummyip.addr = NVS.getInt(ci.key);

        std::cout << ci.key << "\t" << ci.secret << "\t" << typedesc << "\t" << to_string((int)dummyip.bytes[0]) << "." << to_string((int)dummyip.bytes[1])
                  << "." << to_string((int)dummyip.bytes[2]) << "." << to_string((int)dummyip.bytes[3]) << std::endl;
    }
    break;

    default:
        typedesc = "undetermined";
        break;
    }
}

void ConfNvs::begin()
{

    NVS.begin("config");

    // Admin
    CONFIG_ITEMS[CONFIG_ADMIN_AUTH].key = "adm_auth";
    CONFIG_ITEMS[CONFIG_ADMIN_AUTH].type = CONFIG_ITEM_TYPE_INT8;
    CONFIG_ITEMS[CONFIG_ADMIN_AUTH].secret = false;
    // CONFIG_ITEMS[CONFIG_ADMIN_AUTH].val.int8 = 0;

    CONFIG_ITEMS[CONFIG_ADMIN_USERNAME].key = "adm_user";
    CONFIG_ITEMS[CONFIG_ADMIN_USERNAME].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_ADMIN_USERNAME].secret = false;
    // CONFIG_ITEMS[CONFIG_ADMIN_USERNAME].val.str = "admin";

    CONFIG_ITEMS[CONFIG_ADMIN_PASSWORD].key = "adm_pass";
    CONFIG_ITEMS[CONFIG_ADMIN_PASSWORD].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_ADMIN_PASSWORD].secret = true;
    // CONFIG_ITEMS[CONFIG_ADMIN_PASSWORD].val.str = "";

    // MQTT,
    CONFIG_ITEMS[CONFIG_MQTT_HOST].key = "mq_host";
    CONFIG_ITEMS[CONFIG_MQTT_HOST].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_MQTT_HOST].secret = false;

    CONFIG_ITEMS[CONFIG_MQTT_PORT].key = "mq_port";
    CONFIG_ITEMS[CONFIG_MQTT_PORT].type = CONFIG_ITEM_TYPE_UINT16;
    CONFIG_ITEMS[CONFIG_MQTT_PORT].secret = false;

    CONFIG_ITEMS[CONFIG_MQTT_USERNAME].key = "m_user";
    CONFIG_ITEMS[CONFIG_MQTT_USERNAME].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_MQTT_USERNAME].secret = false;

    CONFIG_ITEMS[CONFIG_MQTT_PASSWORD].key = "m_pass";
    CONFIG_ITEMS[CONFIG_MQTT_PASSWORD].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_MQTT_PASSWORD].secret = true;

    CONFIG_ITEMS[CONFIG_MQTT_ROOT_TOPIC].key = "m_topic";
    CONFIG_ITEMS[CONFIG_MQTT_ROOT_TOPIC].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_MQTT_ROOT_TOPIC].secret = false;

    CONFIG_ITEMS[CONFIG_P1_UPD_INT].key = "p1_upd_int";
    CONFIG_ITEMS[CONFIG_P1_UPD_INT].type = CONFIG_ITEM_TYPE_UINT32;
    CONFIG_ITEMS[CONFIG_P1_UPD_INT].secret = false;

    CONFIG_ITEMS[CONFIG_P1_FULL_UPD_INT].key = "p1_full_upd_int";
    CONFIG_ITEMS[CONFIG_P1_FULL_UPD_INT].type = CONFIG_ITEM_TYPE_UINT32;
    CONFIG_ITEMS[CONFIG_P1_FULL_UPD_INT].secret = false;

    // WiFi,
    CONFIG_ITEMS[CONFIG_WIFI_AP_ACTIVE].key = "w_ap_active";
    CONFIG_ITEMS[CONFIG_WIFI_AP_ACTIVE].type = CONFIG_ITEM_TYPE_BOOL;
    CONFIG_ITEMS[CONFIG_WIFI_AP_ACTIVE].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_ACTIVE].val.bool1 = true;

    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID].key = "w_ap_ssid";
    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_SSID].val.str = "Ardumower-AP";

    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID_HIDDEN].key = "w_ap_ssid_hid";
    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID_HIDDEN].type = CONFIG_ITEM_TYPE_BOOL;
    CONFIG_ITEMS[CONFIG_WIFI_AP_SSID_HIDDEN].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_SSID_HIDDEN].val.bool1 = false;

    CONFIG_ITEMS[CONFIG_WIFI_AP_AUTH_MODE].key = "w_ap_auth_mode";
    CONFIG_ITEMS[CONFIG_WIFI_AP_AUTH_MODE].type = CONFIG_ITEM_TYPE_UINT8;
    CONFIG_ITEMS[CONFIG_WIFI_AP_AUTH_MODE].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_AUTH_MODE].val.uint8 = 0;//WIFI_AUTH_OPEN;

    CONFIG_ITEMS[CONFIG_WIFI_AP_PASSWORD].key = "w_ap_pass";
    CONFIG_ITEMS[CONFIG_WIFI_AP_PASSWORD].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_AP_PASSWORD].secret = true;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_PASSWORD].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_AP_GATEWAY].key = "w_ap_gw";
    CONFIG_ITEMS[CONFIG_WIFI_AP_GATEWAY].type = CONFIG_ITEM_TYPE_IP;
    CONFIG_ITEMS[CONFIG_WIFI_AP_GATEWAY].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_GATEWAY].val.ip = config_ip_addr_t(192,168,0,1);

    CONFIG_ITEMS[CONFIG_WIFI_AP_SUBNET].key = "w_ap_subnet";
    CONFIG_ITEMS[CONFIG_WIFI_AP_SUBNET].type = CONFIG_ITEM_TYPE_UINT8;
    CONFIG_ITEMS[CONFIG_WIFI_AP_SUBNET].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_AP_SUBNET].val.uint8 = 24;

    CONFIG_ITEMS[CONFIG_WIFI_STA_ACTIVE].key = "w_sta_active";
    CONFIG_ITEMS[CONFIG_WIFI_STA_ACTIVE].type = CONFIG_ITEM_TYPE_BOOL;
    CONFIG_ITEMS[CONFIG_WIFI_STA_ACTIVE].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_ACTIVE].val.bool1 = false;

    CONFIG_ITEMS[CONFIG_WIFI_STA_COLOR].key = "w_sta_color";
    CONFIG_ITEMS[CONFIG_WIFI_STA_COLOR].type = CONFIG_ITEM_TYPE_COLOR;
    CONFIG_ITEMS[CONFIG_WIFI_STA_COLOR].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_COLOR].val.color.rgba = 0x00000055u;

    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID].key = "w_sta_ssid";
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_SSID].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD].key = "w_sta_pass";
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD].secret = true;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_2].key = "w_sta_ssid_2";
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_2].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_2].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_2].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_2].key = "w_sta_pass_2";
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_2].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_2].secret = true;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_2].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_3].key = "w_sta_ssid_3";
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_3].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_3].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_SSID_3].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_3].key = "w_sta_pass_3";
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_3].type = CONFIG_ITEM_TYPE_STRING;
    CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_3].secret = true;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_PASSWORD_3].val.str = "";

    CONFIG_ITEMS[CONFIG_WIFI_STA_SCAN_MODE_ALL].key = "w_sta_scan_mode";
    CONFIG_ITEMS[CONFIG_WIFI_STA_SCAN_MODE_ALL].type = CONFIG_ITEM_TYPE_BOOL;
    CONFIG_ITEMS[CONFIG_WIFI_STA_SCAN_MODE_ALL].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_SCAN_MODE_ALL].val.bool1 = true;

    CONFIG_ITEMS[CONFIG_WIFI_STA_STATIC].key = "w_sta_static";
    CONFIG_ITEMS[CONFIG_WIFI_STA_STATIC].type = CONFIG_ITEM_TYPE_BOOL;
    CONFIG_ITEMS[CONFIG_WIFI_STA_STATIC].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_STATIC].val.bool1 = false;

    CONFIG_ITEMS[CONFIG_WIFI_STA_IP].key = "w_sta_ip";
    CONFIG_ITEMS[CONFIG_WIFI_STA_IP].type = CONFIG_ITEM_TYPE_IP;
    CONFIG_ITEMS[CONFIG_WIFI_STA_IP].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_IP].val.ip.addr = 0;

    CONFIG_ITEMS[CONFIG_WIFI_STA_GATEWAY].key = "w_sta_gw";
    CONFIG_ITEMS[CONFIG_WIFI_STA_GATEWAY].type = CONFIG_ITEM_TYPE_IP;
    CONFIG_ITEMS[CONFIG_WIFI_STA_GATEWAY].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_GATEWAY].val.ip.addr = 0;

    CONFIG_ITEMS[CONFIG_WIFI_STA_SUBNET].key = "w_sta_subnet";
    CONFIG_ITEMS[CONFIG_WIFI_STA_SUBNET].type = CONFIG_ITEM_TYPE_UINT8;
    CONFIG_ITEMS[CONFIG_WIFI_STA_SUBNET].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_SUBNET].val.uint8 = 24;

    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_A].key = "w_sta_dns_a";
    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_A].type = CONFIG_ITEM_TYPE_IP;
    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_A].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_A].val.ip.addr = 0;

    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_B].key = "w_sta_dns_b";
    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_B].type = CONFIG_ITEM_TYPE_IP;
    CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_B].secret = false;
    // CONFIG_ITEMS[CONFIG_WIFI_STA_DNS_B].val.ip.addr = 0;
}
