int Hase::getPosition() {
	return position;
}
int Hase::getKarotten() {
	return karotten;
}
Hase::Hase() {
	position = 0;
	karotten = 31;
	fehlversuche = 0;
}
bool Hase::ziehe(int felder) {
	kosten = 0;
	for(int i = felder; i>0;i--) {
		kosten += i;
	}
	if(kosten > vorrat) {
		fehlversuche++;
		if(fehlversuche==3) {
			if(felder > position) {
				vorrat += (10*position);
				position = 0;
			} else {
				position -= felder;
				vorrat += (10*felder);
			}
			fehlversuche = 0;
			return true;
		} else {
			return false;
		}
	} else {
		vorrat -= kosten;
		position += felder;
		return true; 
	}
}