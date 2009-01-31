/*
 * Copyright (c) 1997 - 2002 Hansj�rg Malthaner
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

#ifndef warenbauer_t_h
#define warenbauer_t_h

#include "../besch/ware_besch.h"

#include "../tpl/vector_tpl.h"
#include "../tpl/stringhashtable_tpl.h"

class ware_besch_t;

/**
 * Factory-Klasse fuer Waren.
 * "Factory class for goods" (Google)
 * @author Hj. Malthaner
 */
class warenbauer_t
{
private:
	static stringhashtable_tpl<const ware_besch_t *> besch_names;
	static vector_tpl<ware_besch_t *> waren;

	static ware_besch_t *load_passagiere;
	static ware_besch_t *load_post;
	static ware_besch_t *load_nichts;

	// number of different good classes;
	static uint8 max_catg_index;
	// up to this are special freight indexes
	static uint8 max_special_catg_index;

public:
	enum { INDEX_PAS=0, INDEX_MAIL=1, INDEX_NONE=2 };

	static const ware_besch_t *passagiere;
	static const ware_besch_t *post;
	static const ware_besch_t *nichts; //"Nothing".

	static bool alles_geladen();
	static bool register_besch(ware_besch_t *besch);

	static uint8 get_max_catg_index() { return max_catg_index; }

	/**
	* Sucht information zur ware 'name' und gibt die
	* Beschreibung davon zur�ck. Gibt NULL zur�ck wenn die
	* Ware nicht bekannt ist.
	*
	* Searches for information on software 'name' and gives
	* the description of it back. Returns NULL if the product is not known.
	*
	* @param name der nicht-�bersetzte Warenname
	* @author Hj. Malthaner/V. Meyer
	*/
	static const ware_besch_t *get_info(const char* name);

	static const ware_besch_t *get_info(uint16 idx) { return waren[idx]; }

	static uint16 get_waren_anzahl() { return waren.get_count(); }

	// ware by catg
	static const ware_besch_t *get_info_catg(const uint8 catg);

	// ware by catg_index
	static const ware_besch_t *get_info_catg_index(const uint8 catg_index);

	/*
	 * allow to multiply all prices, 1000=1.0
	 * used for the beginner mode
	 */
	static void set_multiplier(sint32 multiplier);
};

#endif
