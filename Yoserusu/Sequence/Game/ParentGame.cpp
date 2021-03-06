#include "Sequence/Parent.h"
#include "Sequence/Game/ParentGame.h"
#include "Sequence/Game/Loading.h"
#include "Sequence/Game/Play.h"
#include "Sequence/Game/Result.h"

#include "Mashiro/Mashiro.h"

namespace Sequence{
namespace Game{

ParentGame::ParentGame() :
mNextSequence( NEXT_NONE ),
mChild( 0 ),
mState( 0 ){
	//最初はReady
	mChild = new Loading();
}

ParentGame::~ParentGame(){
	SAFE_DELETE( mChild );
	SAFE_DELETE( mState );
}

void ParentGame::update( GrandParent* parent ){
	mChild->update( this );
	//遷移判定
	switch ( mNextSequence ){
		case NEXT_LOAD:
			SAFE_DELETE( mChild );
			mChild = new Loading();
			break;
		case NEXT_AUTHE:
			SAFE_DELETE( mChild );
			parent->moveTo( GrandParent::NEXT_AUTHE );
			break;
		case NEXT_PLAY:
			SAFE_DELETE( mChild );
			mChild = new Play();
			break;
		case NEXT_RESULT:
			SAFE_DELETE( mChild );
			mChild = new Result();
			break;
	}
	mNextSequence = NEXT_NONE;
}

void ParentGame::moveTo( NextSequence next ){
	if( mNextSequence != NEXT_NONE ){
		ASSERT( mNextSequence == NEXT_NONE ); //これ以外ありえない
	}
	mNextSequence = next;
}

void ParentGame::startLoading(){
	if( mState ){
		SAFE_DELETE( mState );
	}
	mState = new State();
}

State* ParentGame::getState(){
	return mState;
}

} //namespace Game
} //namespace Sequence