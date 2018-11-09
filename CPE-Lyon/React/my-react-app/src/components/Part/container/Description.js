import React, { Component } from 'react';
import Price from "./Price";

class Description extends Component {
  constructor(props) {
    super(props);
  }
  render() {
    return(
      <div class="table">
        <div> ID : {this.props.part.id} </div>
        <div> NAME : {this.props.part.title} </div>
        <div>
          PRICE : <Price value={this.props.part.price} />
        </div>
      </div>
    );
  }
}

export default Description;
